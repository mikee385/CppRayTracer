#include "Plane.h"
#include <cmath>

Plane::Plane(const Point3D& origin, const Direction3D& normal, const ColorRGB& color)
    : _origin(origin)
    , _normal(normal)
    , material(color)
{}

Plane::Plane(float d, const Vector3D& vector, const ColorRGB& color)
    : _origin(-(d / Dot(vector, vector)) * vector)
    , _normal(vector)
    , material(color)
{}

const Point3D& Plane::GetOrigin() const
{
    return _origin;
}

float Plane::GetD() const
{
    return -Dot(Vector3D(_origin), _normal);
}

IntersectResult Plane::Intersect(const Ray3D& ray) const
{
    float denominator = Dot(ray.Direction, _normal);
    if (std::abs(denominator) < Epsilon)
        return IntersectResult(NO_INTERSECTION, 0.0f);

    float t = Dot(Vector3D(ray.Origin, _origin), _normal) / denominator;
    if (t < 0.0)
        return IntersectResult(NO_INTERSECTION, 0.0f);

    return IntersectResult(INTERSECTION, t);
}

Direction3D Plane::GetNormal(const Point3D&) const
{
    return _normal;
}

Material Plane::GetMaterial(const Point3D&) const
{
    return material;
}
