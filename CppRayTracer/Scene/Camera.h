#ifndef CAMERA_HEADER_GUARD
#define CAMERA_HEADER_GUARD

#include "../Geometry/Geometry.h"
#include "../Table.h"

namespace scene
{
    class Camera
    {
    private:
        size_t _imageWidth;
        size_t _imageHeight;

        float _xMin;
        float _yMax;
        float _dx;
        float _dy;

        float _distanceToPlane;
        geometry::Point3D _position;
        geometry::Matrix3D _orientation;

        geometry::Point3D GetPixelCenter(size_t row, size_t column) const;
        geometry::Point3D ConvertCameraToWorld(const geometry::Point3D& pointInCamera) const;

    public:
        Camera(size_t imageWidth, size_t imageHeight, float fieldOfView, float distanceToPlane, const geometry::Point3D& position, const geometry::Point3D& lookAtPoint);
        Camera(size_t imageWidth, size_t imageHeight, float planeWidth, float planeHeight, float distanceToPlane, const geometry::Point3D& position, const geometry::Point3D& lookAtPoint);

        const geometry::Point3D& GetPosition() const;
        const geometry::Matrix3D& GetOrientation() const;

        size_t GetImageWidth() const;
        size_t GetImageHeight() const;

        geometry::Ray3D GetPrimaryRay(size_t row, size_t column) const;
        void GetSubRays(size_t row, size_t column, table::Table<geometry::Ray3D>& rays) const;
    };
}

#endif
