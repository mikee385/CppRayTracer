#ifndef SCENE_HEADER_GUARD
#define SCENE_HEADER_GUARD

#include "../ColorRGB.h"
#include "../Table.h"
#include "../Scene/SceneObject.h"
#include "../Scene/SceneLight.h"
#include "../Scene/Camera.h"
#include <vector>

namespace scene
{
    class Scene
    {
    private:
        struct InternalObject
        {
            size_t Index;
            const SceneObject *Object;
            bool IsLight;

            InternalObject(size_t index, const SceneObject* object, bool isLight)
                : Index(index), Object(object), IsLight(isLight)
            {}
        };

        struct InternalLight
        {
            size_t Index;
            const SceneLight *Light;

            InternalLight(size_t index, const SceneLight* light)
                : Index(index), Light(light)
            {}
        };

        ColorRGB _backgroundColor;
        float _refractiveIndex;
        size_t _maxRayDepth;

        std::vector<InternalObject> _items;
        std::vector<InternalLight> _lights;

    public:
        Scene(const ColorRGB& backgroundColor, float refractiveIndex, size_t maxRayDepth);

        void AddLightSource(const SceneLight* light);
        void AddObject(const SceneObject* object);

        struct TraceResult
        {
            ColorRGB Color;
            float Distance;

            TraceResult(const ColorRGB& color, float distance)
                : Color(color), Distance(distance)
            {}
        };

        TraceResult Trace(const geometry::Ray3D& ray, size_t depth) const;
    };
}

#endif
