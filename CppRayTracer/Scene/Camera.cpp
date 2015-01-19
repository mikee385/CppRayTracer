#include "Camera.h"

#include <cmath>
#include <stdexcept>

using namespace geometry;
using namespace table;

static Matrix3D ComputeOrientation(const Point3D& position, const Point3D& lookAtPoint)
{
    Direction3D z = Direction3D(position, lookAtPoint);
    Direction3D x = Cross(Direction3D::UnitY, z).ToUnit();
    Direction3D y = Cross(z, x).ToUnit();
    return Matrix3D(x, y, z);
}

namespace scene
{
    Camera::Camera(size_t imageWidth, size_t imageHeight, float fieldOfView, float distanceToPlane, const Point3D& position, const Point3D& lookAtPoint)
        : _imageWidth(imageWidth)
        , _imageHeight(imageHeight)
        , _distanceToPlane(distanceToPlane)
        , _position(position)
        , _orientation(ComputeOrientation(position, lookAtPoint))
    {
        _yMax = std::tan(fieldOfView / 2.0f * DegreesToRadians) * distanceToPlane;
        _xMin = -_yMax * imageWidth / imageHeight;
        _dx = -2 * _xMin / imageWidth;
        _dy = 2 * _yMax / imageHeight;
    }

    Camera::Camera(size_t imageWidth, size_t imageHeight, float planeWidth, float planeHeight, float distanceToPlane, const Point3D& position, const Point3D& lookAtPoint)
        : _imageWidth(imageWidth)
        , _imageHeight(imageHeight)
        , _distanceToPlane(distanceToPlane)
        , _position(position)
        , _orientation(ComputeOrientation(position, lookAtPoint))
    {
        _xMin = -planeWidth / 2.0f;
        _yMax = planeHeight / 2.0f;
        _dx = planeWidth / imageWidth;
        _dy = planeHeight / imageHeight;
    }

    const Point3D& Camera::GetPosition() const
    {
        return _position;
    }

    const Matrix3D& Camera::GetOrientation() const
    {
        return _orientation;
    }

    size_t Camera::GetImageWidth() const
    {
        return _imageWidth;
    }

    size_t Camera::GetImageHeight() const
    {
        return _imageHeight;
    }

    Ray3D Camera::GetPrimaryRay(size_t row, size_t column) const
    {
        float x = _xMin + _dx * (column + 0.5f);
        float y = _yMax - _dy * (row + 0.5f);
        float z = _distanceToPlane;

        Vector3D directionInCamera = Vector3D(x, y, z);
        Direction3D directionInWorld = directionInCamera.Rotate(_orientation).ToUnit();
        return Ray3D(_position, directionInWorld);
    }

    void Camera::GetSubRays(size_t row, size_t column, Table<Ray3D>& rays) const
    {
        size_t width = rays.GetWidth();
        if (width < 2)
            throw std::out_of_range("rays.width");

        size_t height = rays.GetHeight();
        if (height < 2)
            throw std::out_of_range("rays.height");

        float xStep = _dx / (width - 1);
        float yStep = _dy / (height - 1);

        float x0 = _xMin + _dx * column;
        float y0 = _yMax - _dy * row;
        float z0 = _distanceToPlane;

        for (size_t row = 0; row < height; ++row)
        {
            for (size_t column = 0; column < width; ++column)
            {
                float x = x0 + column*xStep;
                float y = y0 - row*yStep;

                Vector3D directionInCamera = Vector3D(x, y, z0);
                Direction3D directionInWorld = directionInCamera.Rotate(_orientation).ToUnit();
                rays.Set(row, column, Ray3D(_position, directionInWorld));
            }
        }
    }
}
