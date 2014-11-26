#include "Geometry.h"

namespace geometry
{
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