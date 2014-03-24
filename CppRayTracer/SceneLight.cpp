#include "SceneLight.h"

SceneLight::SceneLight(const Point3D& center, float radius, const ColorRGB& color)
    : _sphere(center, radius, color)
{}

IntersectResult SceneLight::Intersect(const Ray3D& ray) const
{
    return _sphere.Intersect(ray);
}

const Point3D& SceneLight::GetCenter() const
{
    return _sphere.GetCenter();
}

float SceneLight::GetRadius() const
{
    return _sphere.GetRadius();
}

Direction3D SceneLight::GetNormal(const Point3D& point) const
{
    return _sphere.GetNormal(point);
}

Material SceneLight::GetMaterial(const Point3D& point) const
{
    return _sphere.GetMaterial(point);
}
