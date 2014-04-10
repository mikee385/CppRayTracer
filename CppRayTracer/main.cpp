#include "Scene.h"
#include "Sphere.h"
#include "Plane.h"
#include "PPM_Image.h"
#include <chrono>
#include <iostream>
#include <memory>
#include <vector>
using namespace std;

int main()
{
    chrono::system_clock::time_point start = chrono::high_resolution_clock::now();

    //--------------------------------------------------------------------------
    // Scratchapixel Tutorial
    //--------------------------------------------------------------------------

    //const size_t width = 640;
    //const size_t height = 480;
    //const float fieldOfView = 30;

    //Scene scene(ColorRGB(2.0f, 2.0f, 2.0f), 1.0f, 5);

    //std::unique_ptr<Sphere> groundSphere(new Sphere(Point3D(0, -10004, 20), 10000, MaterialBuilder()
    //    .Color(ColorRGB(0.20f, 0.20f, 0.20f))
    //    .Diffuse(1.0f)
    //    .Specular(0.0f)
    //    .Shininess(0)
    //    .Reflection(0.0f)
    //    .Refraction(0.0f)
    //    .RefractiveIndex(0.0f)));
    //scene.AddObject(groundSphere.get());

    //std::unique_ptr<Sphere> sphere1(new Sphere(Point3D(0, 0, 20), 4, MaterialBuilder()
    //    .Color(ColorRGB(1.00f, 0.32f, 0.36f))
    //    .Diffuse(1.0f)
    //    .Specular(0.0f)
    //    .Shininess(0)
    //    .Reflection(1.0f)
    //    .Refraction(0.5f)
    //    .RefractiveIndex(1.1f)));
    //scene.AddObject(sphere1.get());

    //std::unique_ptr<Sphere> sphere2(new Sphere(Point3D(5, -1, 15), 2, MaterialBuilder()
    //    .Color(ColorRGB(0.90f, 0.76f, 0.46f))
    //    .Diffuse(1.0f)
    //    .Specular(0.0f)
    //    .Shininess(0)
    //    .Reflection(1.0f)
    //    .Refraction(0.0f)
    //    .RefractiveIndex(0.0f)));
    //scene.AddObject(sphere2.get());

    //std::unique_ptr<Sphere> sphere3(new Sphere(Point3D(5, 0, 25), 3, MaterialBuilder()
    //    .Color(ColorRGB(0.65f, 0.77f, 0.97f))
    //    .Diffuse(1.0f)
    //    .Specular(0.0f)
    //    .Shininess(0)
    //    .Reflection(1.0f)
    //    .Refraction(0.0f)
    //    .RefractiveIndex(0.0f)));
    //scene.AddObject(sphere3.get());

    //std::unique_ptr<Sphere> sphere4(new Sphere(Point3D(-5.5, 0, 15), 3, MaterialBuilder()
    //    .Color(ColorRGB(0.90f, 0.90f, 0.90f))
    //    .Diffuse(1.0f)
    //    .Specular(0.0f)
    //    .Shininess(0)
    //    .Reflection(1.0f)
    //    .Refraction(0.0f)
    //    .RefractiveIndex(0.0f)));
    //scene.AddObject(sphere4.get());

    //std::unique_ptr<SceneLight> lightSource(new SceneLight(Point3D(0, 20, 30), 3.0f, ColorRGB(3.0f, 3.0f, 3.0f)));
    //scene.AddLightSource(lightSource.get());

    //std::unique_ptr<Camera> camera(new Camera(width, height, fieldOfView, 1, Point3D::Origin, Point3D(0, 0, 1)));
    //scene.AddCamera(camera.get());

    //scene.Render();

    //PPM_Image image("mine.ppm");
    //image.Save(camera->GetImage());

    //--------------------------------------------------------------------------
    // flipcode Tutorial, version 1 & version 2
    //--------------------------------------------------------------------------

    //const size_t width = 800;
    //const size_t height = 600;

    //Scene scene(ColorRGB::Color_Black, 1.0f, 5);

    //std::unique_ptr<Plane> groundPlane(new Plane(4.4f, Direction3D(0, 1, 0), MaterialBuilder()
    //    .Color(ColorRGB(0.4f, 0.3f, 0.3f))
    //    .Diffuse(1.0f)
    //    .Specular(0.0f)
    //    .Shininess(0)
    //    .Reflection(0.0f)));
    //scene.AddObject(groundPlane.get());

    //std::unique_ptr<Sphere> bigSphere(new Sphere(Point3D(1, -0.8f, 3), 2.5f, MaterialBuilder()
    //    .Color(ColorRGB(0.7f, 0.7f, 0.7f))
    //    .Diffuse(0.2f)
    //    .Specular(0.8f)
    //    .Shininess(20)
    //    .Reflection(0.6f)));
    //scene.AddObject(bigSphere.get());

    //std::unique_ptr<Sphere> smallSphere(new Sphere(Point3D(-5.5f, -0.5, 7), 2, MaterialBuilder()
    //    .Color(ColorRGB(0.7f, 0.7f, 1.0f))
    //    .Diffuse(0.1f)
    //    .Specular(0.9f)
    //    .Shininess(20)
    //    .Reflection(1.0f)));
    //scene.AddObject(smallSphere.get());

    //std::unique_ptr<SceneLight> lightSource1(new SceneLight(Point3D(0, 5, 5), 0.1f, ColorRGB(0.6f, 0.6f, 0.6f)));
    //scene.AddLightSource(lightSource1.get());

    //std::unique_ptr<SceneLight> lightSource2(new SceneLight(Point3D(2, 5, 1), 0.1f, ColorRGB(0.7f, 0.7f, 0.9f)));
    //scene.AddLightSource(lightSource2.get());

    //std::unique_ptr<Camera> camera(new Camera(width, height, 8, 6, 5, Point3D(0, 0, -5), Point3D(0, 0, 1)));
    //scene.AddCamera(camera.get());

    //scene.Render();

    //PPM_Image image("mine.ppm");
    //image.Save(camera->GetImage());

    //--------------------------------------------------------------------------
    // flipcode Tutorial, version 3
    //--------------------------------------------------------------------------

    const size_t width = 800;
    const size_t height = 600;

    Scene scene(ColorRGB::Color_Black, 1.0f, 5);

    std::unique_ptr<Plane> groundPlane(new Plane(4.4f, Direction3D(0, 1, 0), MaterialBuilder()
        .Color(ColorRGB(0.4f, 0.3f, 0.3f))
        .Diffuse(1.0f)
        .Specular(0.8f)
        .Shininess(20)
        .Reflection(0.0f)
        .Refraction(0.0f)
        .RefractiveIndex(0.0f)));
    scene.AddObject(groundPlane.get());

    std::unique_ptr<Sphere> bigSphere(new Sphere(Point3D(2, 0.8f, 3), 2.5f, MaterialBuilder()
        .Color(ColorRGB(0.7f, 0.7f, 1.0f))
        .Diffuse(0.2f)
        .Specular(0.8f)
        .Shininess(20)
        .Reflection(0.2f)
        .Refraction(0.8f)
        .RefractiveIndex(1.3f)));
    scene.AddObject(bigSphere.get());

    std::unique_ptr<Sphere> smallSphere(new Sphere(Point3D(-5.5f, -0.5, 7), 2, MaterialBuilder()
        .Color(ColorRGB(0.7f, 0.7f, 1.0f))
        .Diffuse(0.1f)
        .Specular(0.8f)
        .Shininess(20)
        .Reflection(0.5f)
        .Refraction(0.0f)
        .RefractiveIndex(1.3f)));
    scene.AddObject(smallSphere.get());

    std::unique_ptr<SceneLight> lightSource1(new SceneLight(Point3D(0, 5, 5), 0.1f, ColorRGB(0.4f, 0.4f, 0.4f)));
    scene.AddLightSource(lightSource1.get());

    std::unique_ptr<SceneLight> lightSource2(new SceneLight(Point3D(-3, 5, 1), 0.1f, ColorRGB(0.6f, 0.6f, 0.8f)));
    scene.AddLightSource(lightSource2.get());

    std::unique_ptr<Sphere> extraSphere(new Sphere(Point3D(-1.5f, -3.8f, 1), 1.5f, MaterialBuilder()
        .Color(ColorRGB(1.0f, 0.4f, 0.4f))
        .Diffuse(0.2f)
        .Specular(0.8f)
        .Shininess(20)
        .Reflection(0.0f)
        .Refraction(0.8f)
        .RefractiveIndex(1.5f)));
    scene.AddObject(extraSphere.get());

    std::unique_ptr<Plane> backPlane(new Plane(12, Vector3D(0.4f, 0, -1), MaterialBuilder()
        .Color(ColorRGB(0.5f, 0.3f, 0.5f))
        .Diffuse(0.6f)
        .Specular(0.0f)
        .Shininess(0)
        .Reflection(0.0f)
        .Refraction(0.0f)
        .RefractiveIndex(0.0f)));
    scene.AddObject(backPlane.get());

    std::unique_ptr<Plane> ceilingPlane(new Plane(7.4f, Direction3D(0, -1, 0), MaterialBuilder()
        .Color(ColorRGB(0.4f, 0.7f, 0.7f))
        .Diffuse(0.5f)
        .Specular(0.0f)
        .Shininess(0)
        .Reflection(0.0f)
        .Refraction(0.0f)
        .RefractiveIndex(0.0f)));
    scene.AddObject(ceilingPlane.get());

    std::vector<std::unique_ptr<Sphere>> gridSpheres;
    for (size_t x = 0; x < 8; x++)
    {
        for (size_t y = 0; y < 7; y++)
        {
            std::unique_ptr<Sphere> gridSphere(new Sphere(Point3D(-4.5f + x * 1.5f, -4.3f + y * 1.5f, 10), 0.3f, MaterialBuilder()
                .Color(ColorRGB(0.3f, 1.0f, 0.4f))
                .Diffuse(0.6f)
                .Specular(0.6f)
                .Shininess(20)
                .Reflection(0.0f)
                .Refraction(0.0f)
                .RefractiveIndex(0.0f)));
            scene.AddObject(gridSphere.get());

            gridSpheres.emplace_back(std::move(gridSphere));
        }
    }

    std::unique_ptr<Camera> camera(new Camera(width, height, 8, 6, 5, Point3D(0, 0, -5), Point3D(0, 0, 1)));
    scene.AddCamera(camera.get());

    scene.Render();

    PPM_Image image("mine.ppm");
    image.Save(camera->GetImage());

    //--------------------------------------------------------------------------

    chrono::system_clock::time_point end = chrono::high_resolution_clock::now();
    chrono::milliseconds elapsed = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "Elapsed time: " << elapsed.count() << endl;
    system("pause");

    return 0;
}
