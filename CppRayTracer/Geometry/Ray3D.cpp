#include "Geometry.h"

namespace geometry
{
    Ray3D::Ray3D(const Point3D& origin, const Direction3D& direction)
        : Origin(origin), Direction(direction)
    {}

    Point3D Ray3D::Point(float distance) const
    {
        return Origin.Translate(Direction, distance);
    }

    bool Ray3D::Equals(const Ray3D& other) const
    {
        return
            Origin.Equals(other.Origin) &&
            Direction.Equals(other.Direction);
    }

    bool Ray3D::Equals(const Ray3D& other, float tolerance) const
    {
        return
            Origin.Equals(other.Origin, tolerance) &&
            Direction.Equals(other.Direction, tolerance);
    }

    bool operator==(const Ray3D& ray1, const Ray3D& ray2)
    {
        return ray1.Equals(ray2);
    }

    bool operator!=(const Ray3D& ray1, const Ray3D& ray2)
    {
        return !ray1.Equals(ray2);
    }

    bool operator<(const Ray3D& ray1, const Ray3D& ray2)
    {
        return (ray1.Origin < ray2.Origin) || ((ray1.Origin == ray2.Origin) && ((ray1.Direction < ray2.Direction)));
    }

    bool operator<=(const Ray3D& ray1, const Ray3D& ray2)
    {
        return !(ray2 < ray1);
    }

    bool operator>(const Ray3D& ray1, const Ray3D& ray2)
    {
        return ray2 < ray1;
    }

    bool operator>=(const Ray3D& ray1, const Ray3D& ray2)
    {
        return !(ray1 < ray2);
    }
}
