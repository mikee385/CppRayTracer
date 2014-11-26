#ifndef SCENE_OBJECT_HEADER_GUARD
#define SCENE_OBJECT_HEADER_GUARD

#include "../Material.h"
#include "../Geometry/Geometry.h"

enum IntersectionType
{
    NO_INTERSECTION,
    INTERSECTION
};

struct IntersectResult
{
    IntersectionType Type;
    float Distance;

    IntersectResult(IntersectionType type, float distance)
        : Type(type)
        , Distance(distance)
    {}
};

class SceneObject
{
public:
    virtual IntersectResult Intersect(const Ray3D& ray) const = 0;

    virtual Direction3D GetNormal(const Point3D& point) const = 0;
    virtual Material GetMaterial(const Point3D& point) const = 0;

    virtual ~SceneObject() {}
};

#endif
