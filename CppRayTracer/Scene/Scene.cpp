#include "Scene.h"
#include <cmath>

using namespace color;
using namespace geometry;
using namespace material;

static const float Bias = 1.0e-4f;

namespace scene
{
    Scene::Scene(const ColorRGB& backgroundColor, float refractiveIndex, size_t maxRayDepth)
        : _backgroundColor(backgroundColor)
        , _refractiveIndex(refractiveIndex)
        , _maxRayDepth(maxRayDepth)
    {
    }

    void Scene::AddLightSource(const SceneLight* light)
    {
        const SceneObject& object = *light;

        size_t index = _items.size();
        _items.push_back(InternalObject(index, &object, true));
        _lights.push_back(InternalLight(index, light));
    }

    void Scene::AddObject(const SceneObject* object)
    {
        size_t index = _items.size();
        _items.push_back(InternalObject(index, object, false));
    }

    Scene::TraceResult Scene::Trace(const Ray3D& ray, size_t depth) const
    {
        IntersectResult nearestIntersection(NO_INTERSECTION, 0.0f);
        InternalObject nearestItem(0, NULL, false);

        // Find the nearest object that the ray intersects.
        for (std::vector<InternalObject>::const_iterator item = _items.begin(), end = _items.end(); item != end; ++item)
        {
            IntersectResult currentIntersection = item->Object->Intersect(ray);
            if (currentIntersection.Type != NO_INTERSECTION)
            {
                if (nearestIntersection.Type == NO_INTERSECTION || currentIntersection.Distance < nearestIntersection.Distance)
                {
                    nearestIntersection = currentIntersection;
                    nearestItem = *item;
                }
            }
        }

        // If the ray doesn't hit any objects, return the background color.
        if (nearestIntersection.Type == NO_INTERSECTION)
            return TraceResult(_backgroundColor, 0.0f);

        // Get the point where the ray intersects the object.
        Point3D point = ray.Point(nearestIntersection.Distance);

        // If the ray intersects a light source, simply return the color of the light.
        if (nearestItem.IsLight)
            return TraceResult(nearestItem.Object->GetMaterial(point).Color, nearestIntersection.Distance);

        // Get the surface normal and color at the intersection point.
        Direction3D normal = nearestItem.Object->GetNormal(point);
        Material surfaceMaterial = nearestItem.Object->GetMaterial(point);

        // Calculate the color at the intersection point.
        ColorRGB totalRayColor = ColorRGB::Color_Black;

        if (depth < _maxRayDepth)
        {
            // TODO: Add Fresnel effects (?)

            // Calculate the color from the reflected ray.
            float reflection = surfaceMaterial.Reflection;
            if (reflection > 0.0f)
            {
                Direction3D reflectedDirection = (ray.Direction - 2.0f * Dot(ray.Direction, normal) * normal).ToUnit();
                Point3D nearbyPoint = point.Translate(reflectedDirection, Bias);
                TraceResult reflectedResult = Trace(Ray3D(nearbyPoint, reflectedDirection), depth + 1);
                totalRayColor += reflection * reflectedResult.Color * surfaceMaterial.Color;
            }

            // Calculate the color from the refracted ray.
            float refraction = surfaceMaterial.Refraction;
            if (refraction > 0.0f)
            {
                float n, cosI;
                if (Dot(ray.Direction, normal) > 0.0f)
                {
                    // Internal refraction
                    n = surfaceMaterial.RefractiveIndex / _refractiveIndex;
                    cosI = -Dot(ray.Direction, -normal);
                }
                else
                {
                    // External refraction
                    n = _refractiveIndex / surfaceMaterial.RefractiveIndex;
                    cosI = -Dot(ray.Direction, normal);
                }

                float cos2T = 1 - n * n * (1 - cosI * cosI);
                if (cos2T > 0.0f)
                {
                    Direction3D refractedDirection = (n * ray.Direction + (n * cosI - std::sqrt(cos2T)) * normal).ToUnit();
                    Point3D nearbyPoint = point.Translate(refractedDirection, Bias);
                    TraceResult refractedResult = Trace(Ray3D(nearbyPoint, refractedDirection), depth + 1);

                    // Beer's Law
                    ColorRGB absorbance = surfaceMaterial.Color * 0.15f * -refractedResult.Distance;
                    ColorRGB transparency = ColorRGB(expf(absorbance.Red), expf(absorbance.Green), expf(absorbance.Blue));
                    totalRayColor += refractedResult.Color * transparency;
                }
            }
        }

        // Calculate the color from each light in the scene.
        for (std::vector<InternalLight>::const_iterator lightItem = _lights.begin(), end = _lights.end(); lightItem != end; ++lightItem)
        {
            const SceneLight *light = lightItem->Light;
            ColorRGB lightColor = light->GetMaterial(point).Color;
            Vector3D vectorToLight = Vector3D(point, light->GetCenter());
            float distanceToLight = vectorToLight.Magnitude();
            Direction3D directionToLight = vectorToLight.ToUnit();

            // Calculate the shading from the light.
            float shade = 1.0f;
            Point3D nearbyPoint = point.Translate(directionToLight, Bias);
            Ray3D shadowRay = Ray3D(nearbyPoint, directionToLight);
            for (std::vector<InternalObject>::const_iterator shadowItem = _items.begin(), shadowEnd = _items.end(); shadowItem != shadowEnd; ++shadowItem)
            {
                if (shadowItem->Index != lightItem->Index)
                {
                    IntersectResult shadowResult = shadowItem->Object->Intersect(shadowRay);
                    if (shadowResult.Type != NO_INTERSECTION && shadowResult.Distance < distanceToLight)
                    {
                        shade = 0.0f;
                        break;
                    }
                }
            }

            if (shade != 0.0f)
            {
                // Calculate the diffusive lighting from the light.
                float diffuse = surfaceMaterial.Diffuse;
                if (diffuse > 0.0f)
                {
                    float percentageOfLight = Dot(normal, directionToLight);
                    if (percentageOfLight > 0.0f)
                        totalRayColor += shade * diffuse * percentageOfLight * lightColor * surfaceMaterial.Color;
                }

                // Calculate the specular lighting from the light.
                float specular = surfaceMaterial.Specular;
                int shininess = surfaceMaterial.Shininess;
                if (specular > 0.0f && shininess > 0)
                {
                    Direction3D reflectedDirection = (directionToLight - 2.0f * Dot(directionToLight, normal) * normal).ToUnit();
                    float percentageOfLight = Dot(ray.Direction, reflectedDirection);
                    if (percentageOfLight > 0.0f)
                        totalRayColor += shade * specular * std::pow(percentageOfLight, shininess) * lightColor;
                }
            }
        }

        return TraceResult(totalRayColor, nearestIntersection.Distance);
    }
}
