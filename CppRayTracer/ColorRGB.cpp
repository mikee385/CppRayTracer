#include "ColorRGB.h"

namespace color
{
    const ColorRGB ColorRGB::Color_White = ColorRGB(1.0f, 1.0f, 1.0f);
    const ColorRGB ColorRGB::Color_Black = ColorRGB(0.0f, 0.0f, 0.0f);
    const ColorRGB ColorRGB::Color_Red = ColorRGB(1.0f, 0.0f, 0.0f);
    const ColorRGB ColorRGB::Color_Green = ColorRGB(0.0f, 1.0f, 0.0f);
    const ColorRGB ColorRGB::Color_Blue = ColorRGB(0.0f, 0.0f, 1.0f);

    ColorRGB::ColorRGB()
        : Red(0.0f), Green(0.0f), Blue(0.0f)
    {}

    ColorRGB::ColorRGB(float red, float green, float blue)
        : Red(red), Green(green), Blue(blue)
    {}

    ColorRGB& ColorRGB::operator+= (const ColorRGB& other)
    {
        Red += other.Red;
        Green += other.Green;
        Blue += other.Blue;
        return *this;
    }

    ColorRGB& ColorRGB::operator*= (float scale)
    {
        Red *= scale;
        Green *= scale;
        Blue *= scale;
        return *this;
    }

    ColorRGB& ColorRGB::operator*= (const ColorRGB& other)
    {
        Red *= other.Red;
        Green *= other.Green;
        Blue *= other.Blue;
        return *this;
    }

    ColorRGB operator+(const ColorRGB& color1, const ColorRGB& color2)
    {
        return ColorRGB(
            color1.Red + color2.Red,
            color1.Green + color2.Green,
            color1.Blue + color2.Blue);
    }

    ColorRGB operator*(const ColorRGB& color, float scale)
    {
        return ColorRGB(
            color.Red * scale,
            color.Green * scale,
            color.Blue * scale);
    }

    ColorRGB operator*(float scale, const ColorRGB& color)
    {
        return ColorRGB(
            color.Red * scale,
            color.Green * scale,
            color.Blue * scale);
    }

    ColorRGB operator*(const ColorRGB& color1, const ColorRGB& color2)
    {
        return ColorRGB(
            color1.Red * color2.Red,
            color1.Green * color2.Green,
            color1.Blue * color2.Blue);
    }
}
