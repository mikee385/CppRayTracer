#ifndef SCENE_HEADER_GUARD
#define SCENE_HEADER_GUARD

#include "Camera.h"
#include "ColorRGB.h"
#include "SceneLight.h"
#include "SceneObject.h"
#include "Table.h"
#include <vector>

class Scene
{
private:
    struct SceneItem
    {
        const SceneObject *Object;
        bool IsLight;

        SceneItem(const SceneObject* object, bool isLight)
            : Object(object), IsLight(isLight)
        {}
    };

    struct TraceResult
    {
        ColorRGB Color;
        float Distance;

        TraceResult(const ColorRGB& color, float distance)
            : Color(color), Distance(distance)
        {}
    };

    ColorRGB _backgroundColor;
    float _refractiveIndex;
    size_t _maxRayDepth;

    std::vector<Camera*> _cameras;
    std::vector<SceneItem> _items;

    TraceResult Trace(const Ray3D& ray, size_t depth);

public:
    Scene(const ColorRGB& backgroundColor, float refractiveIndex, size_t maxRayDepth);

    void AddCamera(Camera* camera);
    void AddLightSource(const SceneLight* light);
    void AddObject(const SceneObject* object);

    void Render();
};

#endif
