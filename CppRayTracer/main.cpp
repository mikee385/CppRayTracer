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

    //std::unique_ptr<Sphere> groundSphere(new Sphere(Point3D(0, -10004, 20), 10000, ColorRGB(0.20f, 0.20f, 0.20f)));
    //groundSphere->material.Diffuse = 1.0f;
    //groundSphere->material.Specular = 0.0f;
    //groundSphere->material.Shininess = 0;
    //groundSphere->material.Reflection = 0.0f;
    //groundSphere->material.Refraction = 0.0f;
    //groundSphere->material.RefractiveIndex = 0.0f;
    //scene.AddObject(groundSphere.get());

    //std::unique_ptr<Sphere> sphere1(new Sphere(Point3D(0, 0, 20), 4, ColorRGB(1.00f, 0.32f, 0.36f)));
    //sphere1->material.Diffuse = 1.0f;
    //sphere1->material.Specular = 0.0f;
    //sphere1->material.Shininess = 0;
    //sphere1->material.Reflection = 1.0f;
    //sphere1->material.Refraction = 0.5f;
    //sphere1->material.RefractiveIndex = 1.1f;
    //scene.AddObject(sphere1.get());

    //std::unique_ptr<Sphere> sphere2(new Sphere(Point3D(5, -1, 15), 2, ColorRGB(0.90f, 0.76f, 0.46f)));
    //sphere2->material.Diffuse = 1.0f;
    //sphere2->material.Specular = 0.0f;
    //sphere2->material.Shininess = 0;
    //sphere2->material.Reflection = 1.0f;
    //sphere2->material.Refraction = 0.0f;
    //sphere2->material.RefractiveIndex = 0.0f;
    //scene.AddObject(sphere2.get());

    //std::unique_ptr<Sphere> sphere3(new Sphere(Point3D(5, 0, 25), 3, ColorRGB(0.65f, 0.77f, 0.97f)));
    //sphere3->material.Diffuse = 1.0f;
    //sphere3->material.Specular = 0.0f;
    //sphere3->material.Shininess = 0;
    //sphere3->material.Reflection = 1.0f;
    //sphere3->material.Refraction = 0.0f;
    //sphere3->material.RefractiveIndex = 0.0f;
    //scene.AddObject(sphere3.get());

    //std::unique_ptr<Sphere> sphere4(new Sphere(Point3D(-5.5, 0, 15), 3, ColorRGB(0.90f, 0.90f, 0.90f)));
    //sphere4->material.Diffuse = 1.0f;
    //sphere4->material.Specular = 0.0f;
    //sphere4->material.Shininess = 0;
    //sphere4->material.Reflection = 1.0f;
    //sphere4->material.Refraction = 0.0f;
    //sphere4->material.RefractiveIndex = 0.0f;
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

    //std::unique_ptr<Plane> groundPlane(new Plane(4.4f, Direction3D(0, 1, 0), ColorRGB(0.4f, 0.3f, 0.3f)));
    //groundPlane->material.Diffuse = 1.0f;
    //groundPlane->material.Specular = 0.0f;
    //groundPlane->material.Shininess = 0;
    //groundPlane->material.Reflection = 0.0f;
    //scene.AddObject(groundPlane.get());

    //std::unique_ptr<Sphere> bigSphere(new Sphere(Point3D(1, -0.8f, 3), 2.5f, ColorRGB(0.7f, 0.7f, 0.7f)));
    //bigSphere->material.Diffuse = 0.2f;
    //bigSphere->material.Specular = 0.8f;
    //bigSphere->material.Shininess = 20;
    //bigSphere->material.Reflection = 0.6f;
    //scene.AddObject(bigSphere.get());

    //std::unique_ptr<Sphere> smallSphere(new Sphere(Point3D(-5.5f, -0.5, 7), 2, ColorRGB(0.7f, 0.7f, 1.0f)));
    //smallSphere->material.Diffuse = 0.1f;
    //smallSphere->material.Specular = 0.9f;
    //smallSphere->material.Shininess = 20;
    //smallSphere->material.Reflection = 1.0f;
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

    std::unique_ptr<Plane> groundPlane(new Plane(4.4f, Direction3D(0, 1, 0), ColorRGB(0.4f, 0.3f, 0.3f)));
    groundPlane->material.Diffuse = 1.0f;
    groundPlane->material.Specular = 0.8f;
    groundPlane->material.Shininess = 20;
    groundPlane->material.Reflection = 0.0f;
    groundPlane->material.Refraction = 0.0f;
    groundPlane->material.RefractiveIndex = 0.0f;
    scene.AddObject(groundPlane.get());

    std::unique_ptr<Sphere> bigSphere(new Sphere(Point3D(2, 0.8f, 3), 2.5f, ColorRGB(0.7f, 0.7f, 1.0f)));
    bigSphere->material.Diffuse = 0.2f;
    bigSphere->material.Specular = 0.8f;
    bigSphere->material.Shininess = 20;
    bigSphere->material.Reflection = 0.2f;
    bigSphere->material.Refraction = 0.8f;
    bigSphere->material.RefractiveIndex = 1.3f;
    scene.AddObject(bigSphere.get());

    std::unique_ptr<Sphere> smallSphere(new Sphere(Point3D(-5.5f, -0.5, 7), 2, ColorRGB(0.7f, 0.7f, 1.0f)));
    smallSphere->material.Diffuse = 0.1f;
    smallSphere->material.Specular = 0.8f;
    smallSphere->material.Shininess = 20;
    smallSphere->material.Reflection = 0.5f;
    smallSphere->material.Refraction = 0.0f;
    smallSphere->material.RefractiveIndex = 1.3f;
    scene.AddObject(smallSphere.get());

    std::unique_ptr<SceneLight> lightSource1(new SceneLight(Point3D(0, 5, 5), 0.1f, ColorRGB(0.4f, 0.4f, 0.4f)));
    scene.AddLightSource(lightSource1.get());

    std::unique_ptr<SceneLight> lightSource2(new SceneLight(Point3D(-3, 5, 1), 0.1f, ColorRGB(0.6f, 0.6f, 0.8f)));
    scene.AddLightSource(lightSource2.get());

    std::unique_ptr<Sphere> extraSphere(new Sphere(Point3D(-1.5f, -3.8f, 1), 1.5f, ColorRGB(1.0f, 0.4f, 0.4f)));
    extraSphere->material.Diffuse = 0.2f;
    extraSphere->material.Specular = 0.8f;
    extraSphere->material.Shininess = 20;
    extraSphere->material.Reflection = 0.0f;
    extraSphere->material.Refraction = 0.8f;
    extraSphere->material.RefractiveIndex = 1.5f;
    scene.AddObject(extraSphere.get());

    std::unique_ptr<Plane> backPlane(new Plane(12 / std::sqrt(1.16f), Direction3D(0.4f, 0, -1), ColorRGB(0.5f, 0.3f, 0.5f)));
    backPlane->material.Diffuse = 0.6f;
    backPlane->material.Specular = 0.0f;
    backPlane->material.Shininess = 0;
    backPlane->material.Reflection = 0.0f;
    backPlane->material.Refraction = 0.0f;
    backPlane->material.RefractiveIndex = 0.0f;
    scene.AddObject(backPlane.get());

    std::unique_ptr<Plane> ceilingPlane(new Plane(7.4f, Direction3D(0, -1, 0), ColorRGB(0.4f, 0.7f, 0.7f)));
    ceilingPlane->material.Diffuse = 0.5f;
    ceilingPlane->material.Specular = 0.0f;
    ceilingPlane->material.Shininess = 0;
    ceilingPlane->material.Reflection = 0.0f;
    ceilingPlane->material.Refraction = 0.0f;
    ceilingPlane->material.RefractiveIndex = 0.0f;
    scene.AddObject(ceilingPlane.get());

    std::vector<std::unique_ptr<Sphere>> gridSpheres;
    for (size_t x = 0; x < 8; x++)
    {
        for (size_t y = 0; y < 7; y++)
        {
            std::unique_ptr<Sphere> gridSphere(new Sphere(Point3D(-4.5f + x * 1.5f, -4.3f + y * 1.5f, 10), 0.3f, ColorRGB(0.3f, 1.0f, 0.4f)));
            gridSphere->material.Diffuse = 0.6f;
            gridSphere->material.Specular = 0.6f;
            gridSphere->material.Shininess = 20;
            gridSphere->material.Reflection = 0.0f;
            gridSphere->material.Refraction = 0.0f;
            gridSphere->material.RefractiveIndex = 0.0f;
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
    chrono::seconds elapsed = chrono::duration_cast<chrono::seconds>(end - start);
    cout << "Elapsed time: " << elapsed.count() << endl;
    system("pause");

    return 0;
}
