#include "Material.h"

Material::Material(const ColorRGB& color)
    : Color(color)
    , Diffuse(1.0f)
    , Specular(0.0f)
    , Shininess(0)
    , Reflection(0.0f)
    , Refraction(0.0f)
    , RefractiveIndex(0.0f)
{}

Material::Material(const MaterialBuilder& params)
    : Color(params._color)
    , Diffuse(params._diffuse)
    , Specular(params._specular)
    , Shininess(params._shininess)
    , Reflection(params._reflection)
    , Refraction(params._refraction)
    , RefractiveIndex(params._refractiveIndex)
{}

MaterialBuilder::MaterialBuilder()
    : _color(ColorRGB::Color_White)
    , _diffuse(1.0f)
    , _specular(0.0f)
    , _shininess(0)
    , _reflection(0.0f)
    , _refraction(0.0f)
    , _refractiveIndex(0.0f)
{}

MaterialBuilder& MaterialBuilder::Color(ColorRGB color)
{
    _color = color;
    return *this;
}

MaterialBuilder& MaterialBuilder::Diffuse(float diffuse)
{
    _diffuse = diffuse;
    return *this;
}

MaterialBuilder& MaterialBuilder::Specular(float specular)
{
    _specular = specular;
    return *this;
}

MaterialBuilder& MaterialBuilder::Shininess(int shininess)
{
    _shininess = shininess;
    return *this;
}

MaterialBuilder& MaterialBuilder::Reflection(float reflection)
{
    _reflection = reflection;
    return *this;
}

MaterialBuilder& MaterialBuilder::Refraction(float refraction)
{
    _refraction = refraction;
    return *this;
}

MaterialBuilder& MaterialBuilder::RefractiveIndex(float refractiveIndex)
{
    _refractiveIndex = refractiveIndex;
    return *this;
}
