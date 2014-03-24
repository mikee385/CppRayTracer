#ifndef PLANE_HEADER_GUARD
#define PLANE_HEADER_GUARD

#include "ColorRGB.h"
#include "Geometry.h"
#include "Material.h"
#include "SceneObject.h"

class Plane : public SceneObject
{
private:
    Point3D _origin;
    Direction3D _normal;

public:
    Plane(const Point3D& origin, const Direction3D& normal, const ColorRGB& color);
    Plane(float d, const Direction3D& normal, const ColorRGB& color);

    Material material;
    
    const Point3D& GetOrigin() const;
    float GetD() const;

    virtual IntersectResult Intersect(const Ray3D& ray) const;

    virtual Direction3D GetNormal(const Point3D& point) const;
    virtual Material GetMaterial(const Point3D& point) const;
};

#endif
