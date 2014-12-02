#include "Geometry.h"

#include <cmath>

namespace geometry
{
    Point3D::Point3D(float x, float y, float z)
        : X(x), Y(y), Z(z)
    {}

    Point3D::Point3D(const Vector3D& vector)
        : X(vector.X), Y(vector.Y), Z(vector.Z)
    {}

    const Point3D Point3D::Origin = Point3D(0.0, 0.0, 0.0);

    Point3D Point3D::Translate(const Vector3D& direction, float magnitude) const
    {
        return Point3D(
            X + direction.X * magnitude,
            Y + direction.Y * magnitude,
            Z + direction.Z * magnitude);
    }

    Point3D Point3D::Translate(const Vector3D& vector) const
    {
        return Point3D(
            X + vector.X,
            Y + vector.Y,
            Z + vector.Z);
    }

    Point3D Point3D::Rotate(const Matrix3D& matrix) const
    {
        return Point3D(
            X * matrix.X.X + Y * matrix.Y.X + Z * matrix.Z.X,
            X * matrix.X.Y + Y * matrix.Y.Y + Z * matrix.Z.Y,
            X * matrix.X.Z + Y * matrix.Y.Z + Z * matrix.Z.Z);
    }

    bool Point3D::Equals(const Point3D& other) const
    {
        return
            (X == other.X) &&
            (Y == other.Y) &&
            (Z == other.Z);
    }

    bool Point3D::Equals(const Point3D& other, float tolerance) const
    {
        return
            (std::abs(X - other.X) < tolerance) &&
            (std::abs(Y - other.Y) < tolerance) &&
            (std::abs(Z - other.Z) < tolerance);
    }

    bool operator==(const Point3D& point1, const Point3D& point2)
    {
        return point1.Equals(point2);
    }

    bool operator!=(const Point3D& point1, const Point3D& point2)
    {
        return !point1.Equals(point2);
    }

    bool operator<(const Point3D& point1, const Point3D& point2)
    {
        return (point1.X < point2.X) || ((point1.X == point2.X) && ((point1.Y < point2.Y) || ((point1.Y == point2.Y) && (point1.Z < point2.Z))));
    }

    bool operator<=(const Point3D& point1, const Point3D& point2)
    {
        return !(point2 < point1);
    }

    bool operator>(const Point3D& point1, const Point3D& point2)
    {
        return point2 < point1;
    }

    bool operator>=(const Point3D& point1, const Point3D& point2)
    {
        return !(point1 < point2);
    }

    float Distance(const Point3D& point1, const Point3D& point2)
    {
        return Vector3D(
            point1.X - point2.X,
            point1.Y - point2.Y,
            point1.Z - point2.Z).Magnitude();
    }

    Point3D Midpoint(const Point3D& point1, const Point3D& point2)
    {
        return Point3D(
            0.5f * (point1.X + point2.X),
            0.5f * (point1.Y + point2.Y),
            0.5f * (point1.Z + point2.Z));
    }
}
