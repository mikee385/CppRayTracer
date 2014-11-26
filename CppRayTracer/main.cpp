#include "Scene/Scene.h"
#include "Scene/Sphere.h"
#include "Scene/Plane.h"
#include "PPM_Image.h"

#include <algorithm>
#include <chrono>
#include <iostream>
#include <vector>

using namespace geometry;
using namespace scene;
using namespace std;

#define EXAMPLE_TO_RUN 3

void render(const Scene& scene, Camera& camera);
float calculateGradient(float p1, float p2, float p3, float p4, float p6, float p7, float p8, float p9);

int main()
{
    chrono::system_clock::time_point start = chrono::high_resolution_clock::now();

    //--------------------------------------------------------------------------
    // Scratchapixel Tutorial
    //--------------------------------------------------------------------------

#if EXAMPLE_TO_RUN == 1

    ColorRGB backgroundColor(2.0f, 2.0f, 2.0f);
    Scene scene(backgroundColor, 1.0f, 5);

    Sphere groundSphere(Point3D(0, -10004, 20), 10000, MaterialBuilder()
        .Color(ColorRGB(0.20f, 0.20f, 0.20f))
        .Diffuse(1.0f)
        .Specular(0.0f)
        .Shininess(0)
        .Reflection(0.0f)
        .Refraction(0.0f)
        .RefractiveIndex(0.0f)
    );
    scene.AddObject(&groundSphere);

    Sphere sphere1(Point3D(0, 0, 20), 4, MaterialBuilder()
        .Color(ColorRGB(1.00f, 0.32f, 0.36f))
        .Diffuse(1.0f)
        .Specular(0.0f)
        .Shininess(0)
        .Reflection(1.0f)
        .Refraction(0.5f)
        .RefractiveIndex(1.1f)
    );
    scene.AddObject(&sphere1);

    Sphere sphere2(Point3D(5, -1, 15), 2, MaterialBuilder()
        .Color(ColorRGB(0.90f, 0.76f, 0.46f))
        .Diffuse(1.0f)
        .Specular(0.0f)
        .Shininess(0)
        .Reflection(1.0f)
        .Refraction(0.0f)
        .RefractiveIndex(0.0f)
    );
    scene.AddObject(&sphere2);

    Sphere sphere3(Point3D(5, 0, 25), 3, MaterialBuilder()
        .Color(ColorRGB(0.65f, 0.77f, 0.97f))
        .Diffuse(1.0f)
        .Specular(0.0f)
        .Shininess(0)
        .Reflection(1.0f)
        .Refraction(0.0f)
        .RefractiveIndex(0.0f)
    );
    scene.AddObject(&sphere3);

    Sphere sphere4(Point3D(-5.5, 0, 15), 3, MaterialBuilder()
        .Color(ColorRGB(0.90f, 0.90f, 0.90f))
        .Diffuse(1.0f)
        .Specular(0.0f)
        .Shininess(0)
        .Reflection(1.0f)
        .Refraction(0.0f)
        .RefractiveIndex(0.0f)
    );
    scene.AddObject(&sphere4);

    SceneLight lightSource(Point3D(0, 20, 30), 3.0f, ColorRGB(3.0f, 3.0f, 3.0f));
    scene.AddLightSource(&lightSource);
    
    const size_t width = 640;
    const size_t height = 480;
    const float fieldOfView = 30;
    Camera camera(width, height, fieldOfView, 1, Point3D::Origin, Point3D(0, 0, 1));

#endif

    //--------------------------------------------------------------------------
    // flipcode Tutorial, version 1 & version 2
    //--------------------------------------------------------------------------

#if EXAMPLE_TO_RUN == 2

    Scene scene(ColorRGB::Color_Black, 1.0f, 5);

    Plane groundPlane(4.4f, Direction3D(0, 1, 0), MaterialBuilder()
        .Color(ColorRGB(0.4f, 0.3f, 0.3f))
        .Diffuse(1.0f)
        .Specular(0.0f)
        .Shininess(0)
        .Reflection(0.0f));
    scene.AddObject(&groundPlane);

    Sphere bigSphere(Point3D(1, -0.8f, 3), 2.5f, MaterialBuilder()
        .Color(ColorRGB(0.7f, 0.7f, 0.7f))
        .Diffuse(0.2f)
        .Specular(0.8f)
        .Shininess(20)
        .Reflection(0.6f));
    scene.AddObject(&bigSphere);

    Sphere smallSphere(Point3D(-5.5f, -0.5, 7), 2, MaterialBuilder()
        .Color(ColorRGB(0.7f, 0.7f, 1.0f))
        .Diffuse(0.1f)
        .Specular(0.9f)
        .Shininess(20)
        .Reflection(1.0f));
    scene.AddObject(&smallSphere);

    SceneLight lightSource1(Point3D(0, 5, 5), 0.1f, ColorRGB(0.6f, 0.6f, 0.6f));
    scene.AddLightSource(&lightSource1);

    SceneLight lightSource2(Point3D(2, 5, 1), 0.1f, ColorRGB(0.7f, 0.7f, 0.9f));
    scene.AddLightSource(&lightSource2);
    
    const size_t width = 800;
    const size_t height = 600;
    Camera camera(width, height, 8, 6, 5, Point3D(0, 0, -5), Point3D(0, 0, 1));

#endif

    //--------------------------------------------------------------------------
    // flipcode Tutorial, version 3
    //--------------------------------------------------------------------------

#if EXAMPLE_TO_RUN == 3

    Scene scene(ColorRGB::Color_Black, 1.0f, 5);

    Plane groundPlane(4.4f, Direction3D(0, 1, 0), MaterialBuilder()
        .Color(ColorRGB(0.4f, 0.3f, 0.3f))
        .Diffuse(1.0f)
        .Specular(0.8f)
        .Shininess(20)
        .Reflection(0.0f)
        .Refraction(0.0f)
        .RefractiveIndex(0.0f));
    scene.AddObject(&groundPlane);

    Sphere bigSphere(Point3D(2, 0.8f, 3), 2.5f, MaterialBuilder()
        .Color(ColorRGB(0.7f, 0.7f, 1.0f))
        .Diffuse(0.2f)
        .Specular(0.8f)
        .Shininess(20)
        .Reflection(0.2f)
        .Refraction(0.8f)
        .RefractiveIndex(1.3f));
    scene.AddObject(&bigSphere);

    Sphere smallSphere(Point3D(-5.5f, -0.5, 7), 2, MaterialBuilder()
        .Color(ColorRGB(0.7f, 0.7f, 1.0f))
        .Diffuse(0.1f)
        .Specular(0.8f)
        .Shininess(20)
        .Reflection(0.5f)
        .Refraction(0.0f)
        .RefractiveIndex(1.3f));
    scene.AddObject(&smallSphere);

    SceneLight lightSource1(Point3D(0, 5, 5), 0.1f, ColorRGB(0.4f, 0.4f, 0.4f));
    scene.AddLightSource(&lightSource1);

    SceneLight lightSource2(Point3D(-3, 5, 1), 0.1f, ColorRGB(0.6f, 0.6f, 0.8f));
    scene.AddLightSource(&lightSource2);

    Sphere extraSphere(Point3D(-1.5f, -3.8f, 1), 1.5f, MaterialBuilder()
        .Color(ColorRGB(1.0f, 0.4f, 0.4f))
        .Diffuse(0.2f)
        .Specular(0.8f)
        .Shininess(20)
        .Reflection(0.0f)
        .Refraction(0.8f)
        .RefractiveIndex(1.5f));
    scene.AddObject(&extraSphere);

    Plane backPlane(12, Vector3D(0.4f, 0, -1), MaterialBuilder()
        .Color(ColorRGB(0.5f, 0.3f, 0.5f))
        .Diffuse(0.6f)
        .Specular(0.0f)
        .Shininess(0)
        .Reflection(0.0f)
        .Refraction(0.0f)
        .RefractiveIndex(0.0f));
    scene.AddObject(&backPlane);

    Plane ceilingPlane(7.4f, Direction3D(0, -1, 0), MaterialBuilder()
        .Color(ColorRGB(0.4f, 0.7f, 0.7f))
        .Diffuse(0.5f)
        .Specular(0.0f)
        .Shininess(0)
        .Reflection(0.0f)
        .Refraction(0.0f)
        .RefractiveIndex(0.0f));
    scene.AddObject(&ceilingPlane);

    std::vector<Sphere> gridSpheres;
    for (size_t x = 0; x < 8; x++)
    {
        for (size_t y = 0; y < 7; y++)
        {
            gridSpheres.emplace_back(Point3D(-4.5f + x * 1.5f, -4.3f + y * 1.5f, 10), 0.3f, MaterialBuilder()
                .Color(ColorRGB(0.3f, 1.0f, 0.4f))
                .Diffuse(0.6f)
                .Specular(0.6f)
                .Shininess(20)
                .Reflection(0.0f)
                .Refraction(0.0f)
                .RefractiveIndex(0.0f));
        }
    }
    for (const Sphere& gridSphere : gridSpheres)
        scene.AddObject(&gridSphere);
    
    const size_t width = 800;
    const size_t height = 600;
    Camera camera(width, height, 8, 6, 5, Point3D(0, 0, -5), Point3D(0, 0, 1));

#endif

    render(scene, camera);

    PPM_Image image("mine.ppm");
    image.Save(camera.GetImage());

    //--------------------------------------------------------------------------

    chrono::system_clock::time_point end = chrono::high_resolution_clock::now();
    chrono::milliseconds elapsed = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "Elapsed time: " << elapsed.count() << endl;
    system("pause");

    return 0;
}

void render(const Scene& scene, Camera& camera)
{
    const size_t width = camera.GetImage().GetWidth();
    const size_t height = camera.GetImage().GetHeight();

    // Initial Pixel Coloring
    for (size_t row = 0; row < height; ++row)
    {
        for (size_t column = 0; column < width; ++column)
        {
            Ray3D ray = camera.GetPrimaryRay(row, column);
            Scene::TraceResult result = scene.Trace(ray, 0);

            result.Color.Red = std::min(result.Color.Red, 1.0f);
            result.Color.Green = std::min(result.Color.Green, 1.0f);
            result.Color.Blue = std::min(result.Color.Blue, 1.0f);

            camera.SetPixel(row, column, result.Color);
        }
    }

    // Edge Detection
    Table<bool> isEdge(width, height);
    for (size_t row = 1; row < height - 1; ++row)
    {
        for (size_t column = 1; column < width - 1; ++column)
        {
            ColorRGB p1 = camera.GetPixel(row - 1, column - 1);
            ColorRGB p2 = camera.GetPixel(row - 1, column);
            ColorRGB p3 = camera.GetPixel(row - 1, column + 1);
            ColorRGB p4 = camera.GetPixel(row, column - 1);
            ColorRGB p6 = camera.GetPixel(row, column + 1);
            ColorRGB p7 = camera.GetPixel(row + 1, column - 1);
            ColorRGB p8 = camera.GetPixel(row + 1, column);
            ColorRGB p9 = camera.GetPixel(row + 1, column + 1);

            float r = calculateGradient(p1.Red, p2.Red, p3.Red, p4.Red, p6.Red, p7.Red, p8.Red, p9.Red);
            float g = calculateGradient(p1.Green, p2.Green, p3.Green, p4.Green, p6.Green, p7.Green, p8.Green, p9.Green);
            float b = calculateGradient(p1.Blue, p2.Blue, p3.Blue, p4.Blue, p6.Blue, p7.Blue, p8.Blue, p9.Blue);

            if ((r + b + g) > 0.5f)
                isEdge.Set(row, column, true);
            else
                isEdge.Set(row, column, false);
        }
    }

    // Anti-aliasing
    const size_t subWidth = 3;
    const size_t subHeight = 3;
    const size_t subSize = subWidth * subHeight;
    Table<Ray3D> subRays(subWidth, subHeight, Ray3D(Point3D::Origin, Direction3D::UnitX));
    for (size_t row = 1; row < height - 1; ++row)
    {
        for (size_t column = 1; column < width - 1; ++column)
        {
            if (isEdge.Get(row, column))
            {
                ColorRGB pixelColor = ColorRGB::Color_Black;

                camera.GetSubRays(row, column, subRays);
                for (size_t subRow = 0; subRow < subHeight; ++subRow)
                {
                    for (size_t subColumn = 0; subColumn < subWidth; ++subColumn)
                    {
                        Scene::TraceResult result = scene.Trace(subRays.Get(subRow, subColumn), 0);

                        pixelColor.Red += result.Color.Red / subSize;
                        pixelColor.Green += result.Color.Green / subSize;
                        pixelColor.Blue += result.Color.Blue / subSize;
                    }
                }

                camera.SetPixel(row, column, pixelColor);
            }
        }
    }
}

float calculateGradient(float p1, float p2, float p3,
    float p4, float p6, float p7, float p8, float p9)
{
    float gx = (p3 + 2 * p6 + p9) - (p1 + 2 * p4 + p7);
    float gy = (p1 + 2 * p2 + p3) - (p7 + 2 * p8 + p9);
    return std::sqrt(gx*gx + gy*gy);
}
