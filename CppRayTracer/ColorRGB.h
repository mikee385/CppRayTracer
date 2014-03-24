#ifndef COLOR_RGB_HEADER_GUARD
#define COLOR_RGB_HEADER_GUARD

struct ColorRGB
{
    float Red;
    float Green;
    float Blue;

    static const ColorRGB Color_White;
    static const ColorRGB Color_Black;
    static const ColorRGB Color_Red;
    static const ColorRGB Color_Green;
    static const ColorRGB Color_Blue;

    ColorRGB();
    ColorRGB(float red, float green, float blue);

    ColorRGB& operator+=(const ColorRGB& other);
    ColorRGB& operator*=(float scale);
    ColorRGB& operator*=(const ColorRGB& other);
};

ColorRGB operator+(const ColorRGB& color1, const ColorRGB& color2);
ColorRGB operator*(const ColorRGB& color, float scale);
ColorRGB operator*(float scale, const ColorRGB& color);
ColorRGB operator*(const ColorRGB& color1, const ColorRGB& color2);

#endif
