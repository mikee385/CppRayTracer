#include "Geometry.h"
#include <cmath>
#include <cassert>

namespace geometry
{
    Vector3D::Vector3D(float x, float y, float z)
        : X(x), Y(y), Z(z)
    {}

    Vector3D::Vector3D(const Point3D& from, const Point3D& to)
        : X(to.X - from.X), Y(to.Y - from.Y), Z(to.Z - from.Z)
    {}

    Vector3D::Vector3D(const Point3D& point)
        : X(point.X), Y(point.Y), Z(point.Z)
    {}

    const Vector3D Vector3D::Zero = Vector3D(0.0, 0.0, 0.0);

    float Vector3D::Magnitude() const
    {
        return std::sqrt(X * X + Y * Y + Z * Z);
    }

    Direction3D Vector3D::ToUnit() const
    {
        return Direction3D(*this);
    }

    Matrix3D Vector3D::ToOrthonormalBasis() const
    {
        return Direction3D(*this).ToOrthonormalBasis();
    }

    Vector3D& Vector3D::operator+=(const Vector3D& other)
    {
        X += other.X;
        Y += other.Y;
        Z += other.Z;
        return *this;
    }

    Vector3D& Vector3D::operator-=(const Vector3D& other)
    {
        X -= other.X;
        Y -= other.Y;
        Z -= other.Z;
        return *this;
    }

    Vector3D& Vector3D::operator*=(float scale)
    {
        X *= scale;
        Y *= scale;
        Z *= scale;
        return *this;
    }

    Vector3D& Vector3D::operator/=(float scale)
    {
        assert(scale != 0 && "Division by zero in Vector3D::operator/=(float scale)");

        float invScale = 1 / scale;
        X *= invScale;
        Y *= invScale;
        Z *= invScale;
        return *this;
    }

    Vector3D Vector3D::operator-() const
    {
        return Vector3D(-X, -Y, -Z);
    }

    Vector3D Vector3D::Projection(const Direction3D& direction) const
    {
        return direction * Dot(*this, direction);
    }

    Vector3D Vector3D::Projection(const Vector3D& direction) const
    {
        float denominator = Dot(direction, direction);
        if (denominator > 0.0f)
            return direction * (Dot(*this, direction) / denominator);

        return Vector3D::Zero;
    }

    Vector3D Vector3D::Rotate(const Matrix3D& matrix) const
    {
        return Vector3D(
            X * matrix.X.X + Y * matrix.Y.X + Z * matrix.Z.X,
            X * matrix.X.Y + Y * matrix.Y.Y + Z * matrix.Z.Y,
            X * matrix.X.Z + Y * matrix.Y.Z + Z * matrix.Z.Z);
    }

    bool Vector3D::Equals(const Vector3D& other) const
    {
        return
            (X == other.X) &&
            (Y == other.Y) &&
            (Z == other.Z);
    }

    bool Vector3D::Equals(const Vector3D& other, float tolerance) const
    {
        return
            (std::abs(X - other.X) < tolerance) &&
            (std::abs(Y - other.X) < tolerance) &&
            (std::abs(Z - other.X) < tolerance);
    }

    Vector3D operator+(const Vector3D& vector1, const Vector3D& vector2)
    {
        return Vector3D(
            vector1.X + vector2.X,
            vector1.Y + vector2.Y,
            vector1.Z + vector2.Z);
    }

    Vector3D operator-(const Vector3D& vector1, const Vector3D& vector2)
    {
        return Vector3D(
            vector1.X - vector2.X,
            vector1.Y - vector2.Y,
            vector1.Z - vector2.Z);
    }

    Vector3D operator*(const Vector3D& vector, float scale)
    {
        return Vector3D(
            vector.X * scale,
            vector.Y * scale,
            vector.Z * scale);
    }

    Vector3D operator*(float scale, const Vector3D& vector)
    {
        return Vector3D(
            vector.X * scale,
            vector.Y * scale,
            vector.Z * scale);
    }

    Vector3D operator/(const Vector3D& vector, float scale)
    {
        assert(scale != 0 && "Division by zero in operator/(const Vector3D& vector, float scale)");

        float invScale = 1 / scale;
        return Vector3D(
            vector.X * invScale,
            vector.Y * invScale,
            vector.Z * invScale);
    }

    Vector3D operator/(float scale, const Vector3D& vector)
    {
        assert(scale != 0 && "Division by zero in operator/(float scale, const Vector3D& vector)");

        float invScale = 1 / scale;
        return Vector3D(
            vector.X * invScale,
            vector.Y * invScale,
            vector.Z * invScale);
    }

    bool operator==(const Vector3D& vector1, const Vector3D& vector2)
    {
        return vector1.Equals(vector2);
    }

    bool operator!=(const Vector3D& vector1, const Vector3D& vector2)
    {
        return !vector1.Equals(vector2);
    }

    bool operator<(const Vector3D& vector1, const Vector3D& vector2)
    {
        return (vector1.X < vector2.X) || ((vector1.X == vector2.X) && ((vector1.Y < vector2.Y) || ((vector1.Y == vector2.Y) && (vector1.Z < vector2.Z))));
    }

    bool operator<=(const Vector3D& vector1, const Vector3D& vector2)
    {
        return !(vector2 < vector1);
    }

    bool operator>(const Vector3D& vector1, const Vector3D& vector2)
    {
        return vector2 < vector1;
    }

    bool operator>=(const Vector3D& vector1, const Vector3D& vector2)
    {
        return !(vector1 < vector2);
    }

    float Dot(const Vector3D& vector1, const Vector3D& vector2)
    {
        return vector1.X * vector2.X + vector1.Y * vector2.Y + vector1.Z * vector2.Z;
    }

    Vector3D Cross(const Vector3D& vector1, const Vector3D& vector2)
    {
        return Vector3D(
            vector1.Y * vector2.Z - vector1.Z * vector2.Y,
            vector1.Z * vector2.X - vector1.X * vector2.Z,
            vector1.X * vector2.Y - vector1.Y * vector2.X);
    }
}
