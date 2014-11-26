#ifndef SCENE_LIGHT_HEADER_GUARD
#define SCENE_LIGHT_HEADER_GUARD

#include "../ColorRGB.h"
#include "../Material.h"
#include "../Geometry/Geometry.h"
#include "../Scene/SceneObject.h"
#include "../Scene/Sphere.h"

class SceneLight
{
private:
    Sphere _sphere;

public:
    SceneLight(const Point3D& center, float radius, const ColorRGB& color);

    const Point3D& GetCenter() const;
    float GetRadius() const;
    Material GetMaterial(const Point3D& point) const;
    
    operator const SceneObject&() const;
};

#endif
