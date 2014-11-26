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
    virtual IntersectResult Intersect(const geometry::Ray3D& ray) const = 0;

    virtual geometry::Direction3D GetNormal(const geometry::Point3D& point) const = 0;
    virtual Material GetMaterial(const geometry::Point3D& point) const = 0;

    virtual ~SceneObject() {}
};

#endif
