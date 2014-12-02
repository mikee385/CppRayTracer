#include "SceneLight.h"

using namespace color;
using namespace geometry;
using namespace material;

namespace scene
{
    SceneLight::SceneLight(const Point3D& center, float radius, const ColorRGB& color)
        : _sphere(center, radius, color)
    {}

    const Point3D& SceneLight::GetCenter() const
    {
        return _sphere.GetCenter();
    }

    float SceneLight::GetRadius() const
    {
        return _sphere.GetRadius();
    }

    Material SceneLight::GetMaterial(const Point3D& point) const
    {
        return _sphere.GetMaterial(point);
    }

    SceneLight::operator const SceneObject&() const
    {
        return _sphere;
    }
}
