#include "Geometry.h"

#include <cmath>

namespace geometry
{
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
}
