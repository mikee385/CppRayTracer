#ifndef SPHERE_HEADER_GUARD
#define SPHERE_HEADER_GUARD

#include "../Geometry/Geometry.h"
#include "../Material.h"
#include "../Scene/SceneObject.h"

namespace scene
{
    class Sphere : public SceneObject
    {
    private:
        geometry::Point3D _center;
        float _radius, _radius2;
        material::Material _material;

    public:
        Sphere(const geometry::Point3D& center, float radius, const material::Material& material);

        const geometry::Point3D& GetCenter() const;
        float GetRadius() const;

        virtual IntersectResult Intersect(const geometry::Ray3D& ray) const;

        virtual geometry::Direction3D GetNormal(const geometry::Point3D& point) const;
        virtual material::Material GetMaterial(const geometry::Point3D& point) const;
    };
}

#endif
