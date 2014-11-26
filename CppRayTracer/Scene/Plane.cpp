#include "Plane.h"
#include <cmath>

using namespace geometry;

Plane::Plane(const Point3D& origin, const Direction3D& normal, const Material& material)
    : _origin(origin)
    , _normal(normal)
    , _material(material)
{}

Plane::Plane(float d, const Vector3D& vector, const Material& material)
    : _origin(-(d / Dot(vector, vector)) * vector)
    , _normal(vector)
    , _material(material)
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
    return _material;
}
