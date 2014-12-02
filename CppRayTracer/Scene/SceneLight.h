#ifndef SCENE_LIGHT_HEADER_GUARD
#define SCENE_LIGHT_HEADER_GUARD

#include "../ColorRGB.h"
#include "../Material.h"
#include "../Geometry/Geometry.h"
#include "../Scene/SceneObject.h"
#include "../Scene/Sphere.h"

namespace scene
{
    class SceneLight
    {
    private:
        Sphere _sphere;

    public:
        SceneLight(const geometry::Point3D& center, float radius, const color::ColorRGB& color);

        const geometry::Point3D& GetCenter() const;
        float GetRadius() const;
        material::Material GetMaterial(const geometry::Point3D& point) const;

        operator const SceneObject&() const;
    };
}

#endif
