#ifndef GEOMETRY_HEADER_GUARD
#define GEOMETRY_HEADER_GUARD

namespace geometry 
{
    extern const float Epsilon;
    extern const float Pi;
    extern const float DegreesToRadians;

    struct Point3D;
    struct Vector3D;
    struct Direction3D;
    struct Ray3D;
    struct Matrix3D;

    struct Point3D
    {
        float X;
        float Y;
        float Z;

        Point3D(float x, float y, float z);
        explicit Point3D(const Vector3D& vector);

        static const Point3D Origin;

        Point3D Translate(const Vector3D& direction, float magnitude) const;
        Point3D Translate(const Vector3D& vector) const;
        Point3D Rotate(const Matrix3D& matrix) const;

        bool Equals(const Point3D& other) const;
        bool Equals(const Point3D& other, float tolerance) const;
    };

    bool operator==(const Point3D& point1, const Point3D& point2);
    bool operator!=(const Point3D& point1, const Point3D& point2);
    bool operator<(const Point3D& point1, const Point3D& point2);
    bool operator<=(const Point3D& point1, const Point3D& point2);
    bool operator>(const Point3D& point1, const Point3D& point2);
    bool operator>=(const Point3D& point1, const Point3D& point2);

    float Distance(const Point3D& point1, const Point3D& point2);
    Point3D Midpoint(const Point3D& point1, const Point3D& point2);

    struct Vector3D
    {
        float X;
        float Y;
        float Z;

        Vector3D(float x, float y, float z);
        Vector3D(const Point3D& from, const Point3D& to);
        explicit Vector3D(const Point3D& point);

        static const Vector3D Zero;

        float Magnitude() const;
        Direction3D ToUnit() const;
        Matrix3D ToOrthonormalBasis() const;

        Vector3D& operator+=(const Vector3D& other);
        Vector3D& operator-=(const Vector3D& other);
        Vector3D& operator*=(float scale);
        Vector3D& operator/=(float scale);
        Vector3D operator-() const;

        Vector3D Projection(const Direction3D& direction) const;
        Vector3D Projection(const Vector3D& direction) const;
        Vector3D Rotate(const Matrix3D& matrix) const;

        bool Equals(const Vector3D& other) const;
        bool Equals(const Vector3D& other, float tolerance) const;
    };

    Vector3D operator+(const Vector3D& vector1, const Vector3D& vector2);
    Vector3D operator-(const Vector3D& vector1, const Vector3D& vector2);
    Vector3D operator*(const Vector3D& vector, float scale);
    Vector3D operator*(float scale, const Vector3D& vector);
    Vector3D operator/(const Vector3D& vector, float scale);
    Vector3D operator/(float scale, const Vector3D& vector);

    bool operator==(const Vector3D& vector1, const Vector3D& vector2);
    bool operator!=(const Vector3D& vector1, const Vector3D& vector2);
    bool operator<(const Vector3D& vector1, const Vector3D& vector2);
    bool operator<=(const Vector3D& vector1, const Vector3D& vector2);
    bool operator>(const Vector3D& vector1, const Vector3D& vector2);
    bool operator>=(const Vector3D& vector1, const Vector3D& vector2);

    float Dot(const Vector3D& vector1, const Vector3D& vector2);
    Vector3D Cross(const Vector3D& vector1, const Vector3D& vector2);

    struct Direction3D
    {
    private:

        Vector3D _direction;
        void Normalize();
        Direction3D(float x, float y, float z, bool);

    public:

        Direction3D(float x, float y, float z);
        Direction3D(const Point3D& from, const Point3D& to);
        explicit Direction3D(const Point3D& point);

        explicit Direction3D(const Vector3D& vector);
        operator const Vector3D&() const;

        static const Direction3D UnitX;
        static const Direction3D UnitY;
        static const Direction3D UnitZ;

        float X() const;
        float Y() const;
        float Z() const;

        Matrix3D ToOrthonormalBasis() const;

        Direction3D operator-() const;

        bool Equals(const Direction3D& other) const;
        bool Equals(const Direction3D& other, float tolerance) const;
    };

    struct Ray3D
    {
        Point3D Origin;
        Direction3D Direction;

        Ray3D(const Point3D& origin, const Direction3D& direction);

        Point3D Point(float distance) const;

        bool Equals(const Ray3D& other) const;
        bool Equals(const Ray3D& other, float tolerance) const;
    };

    bool operator==(const Ray3D& ray1, const Ray3D& ray2);
    bool operator!=(const Ray3D& ray1, const Ray3D& ray2);
    bool operator>(const Ray3D& ray1, const Ray3D& ray2);
    bool operator<=(const Ray3D& ray1, const Ray3D& ray2);
    bool operator>(const Ray3D& ray1, const Ray3D& ray2);
    bool operator>=(const Ray3D& ray1, const Ray3D& ray2);

    struct Matrix3D
    {
        Vector3D X;
        Vector3D Y;
        Vector3D Z;

        Matrix3D(const Vector3D& x, const Vector3D& y, const Vector3D& z);

        static const Matrix3D Identity;

        Matrix3D ToOrthonormalBasis() const;

        bool Equals(const Matrix3D& other) const;
        bool Equals(const Matrix3D& other, float tolerance) const;
    };

    bool operator==(const Matrix3D& matrix1, const Matrix3D& matrix2);
    bool operator!=(const Matrix3D& matrix1, const Matrix3D& matrix2);
    bool operator>(const Matrix3D& matrix1, const Matrix3D& matrix2);
    bool operator<=(const Matrix3D& matrix1, const Matrix3D& matrix2);
    bool operator>(const Matrix3D& matrix1, const Matrix3D& matrix2);
    bool operator>=(const Matrix3D& matrix1, const Matrix3D& matrix2);
}

#endif
