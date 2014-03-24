#ifndef SCENE_LIGHT_HEADER_GUARD
#define SCENE_LIGHT_HEADER_GUARD

#include "ColorRGB.h"
#include "Geometry.h"
#include "Material.h"
#include "SceneObject.h"
#include "Sphere.h"

class SceneLight : public SceneObject
{
private:
    Sphere _sphere;

public:
    SceneLight(const Point3D& center, float radius, const ColorRGB& color);

    const Point3D& GetCenter() const;
    float GetRadius() const;

    virtual IntersectResult Intersect(const Ray3D& ray) const;

    virtual Direction3D GetNormal(const Point3D& point) const;
    virtual Material GetMaterial(const Point3D& point) const;
};

#endif
