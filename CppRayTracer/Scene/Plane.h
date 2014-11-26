#ifndef PLANE_HEADER_GUARD
#define PLANE_HEADER_GUARD

#include "../ColorRGB.h"
#include "../Material.h"
#include "../Geometry/Geometry.h"
#include "../Scene/SceneObject.h"

namespace scene
{
    class Plane : public SceneObject
    {
    private:
        geometry::Point3D _origin;
        geometry::Direction3D _normal;
        Material _material;

    public:
        Plane(const geometry::Point3D& origin, const geometry::Direction3D& normal, const Material& material);
        Plane(float d, const geometry::Vector3D& vector, const Material& material);

        const geometry::Point3D& GetOrigin() const;
        float GetD() const;

        virtual IntersectResult Intersect(const geometry::Ray3D& ray) const;

        virtual geometry::Direction3D GetNormal(const geometry::Point3D& point) const;
        virtual Material GetMaterial(const geometry::Point3D& point) const;
    };
}

#endif
