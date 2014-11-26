#include "Sphere.h"
#include <cmath>

Sphere::Sphere(const Point3D& center, float radius, const Material& material)
    : _center(center)
    , _radius(radius)
    , _material(material)
{
    _radius2 = _radius * _radius;
}

const Point3D& Sphere::GetCenter() const
{
    return _center;
}

float Sphere::GetRadius() const
{
    return _radius;
}

IntersectResult Sphere::Intersect(const Ray3D& ray) const
{
    Vector3D sphereToRay = Vector3D(ray.Origin, _center);
    float b = Dot(sphereToRay, ray.Direction);
    if (b < 0)
        return IntersectResult(NO_INTERSECTION, 0.0f);

    float d2 = Dot(sphereToRay, sphereToRay) - b * b;
    if (d2 > _radius2)
        return IntersectResult(NO_INTERSECTION, 0.0f);

    float c = std::sqrt(_radius2 - d2);
    float t = b - c;
    if (t < 0)
        t = b + c;

    return IntersectResult(INTERSECTION, t);
}

Direction3D Sphere::GetNormal(const Point3D& point) const
{
    return Direction3D(_center, point);
}

Material Sphere::GetMaterial(const Point3D&) const
{
    return _material;
}
