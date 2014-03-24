#ifndef MATERIAL_HEADER_GUARD
#define MATERIAL_HEADER_GUARD

#include "ColorRGB.h"

struct Material
{
    ColorRGB Color;
    float Diffuse;
    float Specular;
    int Shininess;
    float Reflection;
    float Refraction;
    float RefractiveIndex;

    Material(const ColorRGB& color)
        : Color(color)
        , Diffuse(1.0f)
        , Specular(0.0f)
        , Shininess(0)
        , Reflection(0.0f)
        , Refraction(0.0f)
        , RefractiveIndex(0.0f)
    {}
};

#endif
