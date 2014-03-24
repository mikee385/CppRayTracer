#ifndef CAMERA_HEADER_GUARD
#define CAMERA_HEADER_GUARD

#include "ColorRGB.h"
#include "Geometry.h"
#include "Table.h"

class Camera
{
private:
    Table<ColorRGB> _image;
    size_t _imageWidth;
    size_t _imageHeight;

    float _xMin;
    float _yMax;
    float _dx;
    float _dy;

    float _distanceToPlane;
    Point3D _position;
    Matrix3D _orientation;

    Point3D GetPixelCenter(size_t row, size_t column) const;
    Point3D ConvertCameraToWorld(const Point3D& pointInCamera) const;

public:
    Camera(size_t imageWidth, size_t imageHeight, float fieldOfView, float distanceToPlane, const Point3D& position, const Point3D& lookAtPoint);
    Camera(size_t imageWidth, size_t imageHeight, float planeWidth, float planeHeight, float distanceToPlane, const Point3D& position, const Point3D& lookAtPoint);

    const Table<ColorRGB>& GetImage() const;

    const Point3D& GetPosition() const;
    const Matrix3D& GetOrientation() const;

    void SetPosition(const Point3D& position);
    void SetOrientation(const Matrix3D& orientation);

    Ray3D GetPrimaryRay(size_t row, size_t column) const;
    void GetSubRays(size_t row, size_t column, Table<Ray3D>& rays) const;

    ColorRGB GetPixel(size_t row, size_t column) const;
    void SetPixel(size_t row, size_t column, const ColorRGB& pixel);
};

#endif
