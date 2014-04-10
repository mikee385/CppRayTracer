#ifndef MATERIAL_HEADER_GUARD
#define MATERIAL_HEADER_GUARD

#include "ColorRGB.h"

class MaterialBuilder;

struct Material
{
    ColorRGB Color;
    float Diffuse;
    float Specular;
    int Shininess;
    float Reflection;
    float Refraction;
    float RefractiveIndex;

    Material(const ColorRGB& color);
    Material(const MaterialBuilder& params);
};

class MaterialBuilder
{
private:
    friend struct Material;

    ColorRGB _color;
    float _diffuse;
    float _specular;
    int _shininess;
    float _reflection;
    float _refraction;
    float _refractiveIndex;

public:
    MaterialBuilder();

    MaterialBuilder& Color(ColorRGB color);
    MaterialBuilder& Diffuse(float diffuse);
    MaterialBuilder& Specular(float specular);
    MaterialBuilder& Shininess(int shininess);
    MaterialBuilder& Reflection(float reflection);
    MaterialBuilder& Refraction(float refraction);
    MaterialBuilder& RefractiveIndex(float refractiveIndex);
};

#endif
