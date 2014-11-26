#include "Geometry.h"
#include <cmath>
#include <cassert>

namespace geometry
{
    const float Epsilon = 1.0e-9f;
    const float Pi = std::atan(1.0f) * 4.0f;
    const float DegreesToRadians = Pi / 180.0f;

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

    void Direction3D::Normalize()
    {
        float magnitude = _direction.Magnitude();
        if (magnitude > 0.0f)
        {
            float invMagnitude = 1 / magnitude;
            _direction.X *= invMagnitude;
            _direction.Y *= invMagnitude;
            _direction.Z *= invMagnitude;
        }
    }

    Direction3D::Direction3D(float x, float y, float z, bool)
        : _direction(Vector3D(x, y, z))
    {}

    Direction3D::Direction3D(float x, float y, float z)
        : _direction(Vector3D(x, y, z))
    {
        Normalize();
    }

    Direction3D::Direction3D(const Point3D& from, const Point3D& to)
        : _direction(Vector3D(from, to))
    {
        Normalize();
    }

    Direction3D::Direction3D(const Point3D& point)
        : _direction(Vector3D(point))
    {
        Normalize();
    }

    Direction3D::Direction3D(const Vector3D& vector)
        : _direction(vector)
    {
        Normalize();
    }

    Direction3D::operator const Vector3D&() const
    {
        return _direction;
    }

    const Direction3D Direction3D::UnitX = Direction3D(1.0, 0.0, 0.0);
    const Direction3D Direction3D::UnitY = Direction3D(0.0, 1.0, 0.0);
    const Direction3D Direction3D::UnitZ = Direction3D(0.0, 0.0, 1.0);

    float Direction3D::X() const
    {
        return _direction.X;
    }

    float Direction3D::Y() const
    {
        return _direction.Y;
    }

    float Direction3D::Z() const
    {
        return _direction.Z;
    }

    Matrix3D Direction3D::ToOrthonormalBasis() const
    {
        if (std::abs(_direction.X) >= std::abs(_direction.Y) && std::abs(_direction.X) >= std::abs(_direction.Z))
        {
            const Vector3D & unitX = _direction;

            float invXYMagnitude = 1.0f / sqrtf(unitX.X * unitX.X + unitX.Y * unitX.Y);
            Vector3D unitY = Vector3D(
                -unitX.Y * invXYMagnitude,
                unitX.X * invXYMagnitude,
                0.0f);

            Vector3D unitZ = Vector3D(
                -unitX.Z * unitY.Y,
                unitX.Z * unitY.X,
                unitX.X * unitY.Y - unitX.Y * unitY.X);

            return Matrix3D(unitX, unitY, unitZ);
        }
        else if (std::abs(_direction.Y) >= std::abs(_direction.Z))
        {
            const Vector3D & unitY = _direction;

            float invYZMagnitude = 1.0f / sqrtf(unitY.Y * unitY.Y + unitY.Z * unitY.Z);
            Vector3D unitZ = Vector3D(
                0.0f,
                -unitY.Z * invYZMagnitude,
                unitY.Y * invYZMagnitude);

            Vector3D unitX = Vector3D(
                unitY.Y * unitZ.Z - unitY.Z * unitZ.Y,
                -unitY.X * unitZ.Z,
                unitY.X * unitZ.Y);

            return Matrix3D(unitX, unitY, unitZ);
        }
        else
        {
            const Vector3D & unitZ = _direction;

            float invZXMagnitude = 1.0f / sqrtf(unitZ.Z * unitZ.Z + unitZ.X * unitZ.X);
            Vector3D unitX = Vector3D(
                unitZ.Z * invZXMagnitude,
                0.0f,
                -unitZ.X * invZXMagnitude);

            Vector3D unitY = Vector3D(
                unitZ.Y * unitX.Z,
                unitZ.Z * unitX.X - unitZ.X * unitX.Z,
                -unitZ.Y * unitX.X);

            return Matrix3D(unitX, unitY, unitZ);
        }
    }

    Direction3D Direction3D::operator-() const
    {
        return Direction3D(-_direction.X, -_direction.Y, -_direction.Z, false);
    }

    bool Direction3D::Equals(const Direction3D& other) const
    {
        return _direction.Equals(other._direction);
    }

    bool Direction3D::Equals(const Direction3D& other, float tolerance) const
    {
        return _direction.Equals(other._direction, tolerance);
    }

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

    Matrix3D::Matrix3D(const Vector3D& x, const Vector3D& y, const Vector3D& z)
        : X(x), Y(y), Z(z)
    {}

    const Matrix3D Matrix3D::Identity = Matrix3D(Direction3D::UnitX, Direction3D::UnitY, Direction3D::UnitZ);

    Matrix3D Matrix3D::ToOrthonormalBasis() const
    {
        Direction3D uX = X.ToUnit();
        Direction3D uY = (Y - Dot(uX, Y) * uX).ToUnit();
        Direction3D uZ = (Z - Dot(uX, Z) * uX - Dot(uY, Z) * uY).ToUnit();

        return Matrix3D(uX, uY, uZ);
    }

    bool Matrix3D::Equals(const Matrix3D& other) const
    {
        return
            X.Equals(other.X) &&
            Y.Equals(other.Y) &&
            Z.Equals(other.Z);
    }

    bool Matrix3D::Equals(const Matrix3D& other, float tolerance) const
    {
        return
            X.Equals(other.X, tolerance) &&
            Y.Equals(other.Y, tolerance) &&
            Z.Equals(other.Z, tolerance);
    }

    bool operator==(const Matrix3D& matrix1, const Matrix3D& matrix2)
    {
        return matrix1.Equals(matrix2);
    }

    bool operator!=(const Matrix3D& matrix1, const Matrix3D& matrix2)
    {
        return !matrix1.Equals(matrix2);
    }

    bool operator<(const Matrix3D& matrix1, const Matrix3D& matrix2)
    {
        return (matrix1.X < matrix2.X) || ((matrix1.X == matrix2.X) && ((matrix1.Y < matrix2.Y) || ((matrix1.Y == matrix2.Y) && (matrix1.Z < matrix2.Z))));
    }

    bool operator<=(const Matrix3D& matrix1, const Matrix3D& matrix2)
    {
        return !(matrix2 < matrix1);
    }

    bool operator>(const Matrix3D& matrix1, const Matrix3D& matrix2)
    {
        return matrix2 < matrix1;
    }

    bool operator>=(const Matrix3D& matrix1, const Matrix3D& matrix2)
    {
        return !(matrix1 < matrix2);
    }
}
