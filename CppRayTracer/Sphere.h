#ifndef SPHERE_HEADER_GUARD
#define SPHERE_HEADER_GUARD

#include "ColorRGB.h"
#include "Geometry.h"
#include "Material.h"
#include "SceneObject.h"

class Sphere : public SceneObject
{
private:
    Point3D _center;
    float _radius, _radius2;
    Material _material;

public:
    Sphere(const Point3D& center, float radius, const Material& material);

    const Point3D& GetCenter() const;
    float GetRadius() const;

    virtual IntersectResult Intersect(const Ray3D& ray) const;

    virtual Direction3D GetNormal(const Point3D& point) const;
    virtual Material GetMaterial(const Point3D& point) const;
};

#endif
