#include "Image.h"

#include <fstream>
#include <algorithm>

using namespace color;
using namespace table;

namespace image
{
    unsigned char ConvertToUnsignedChar(float value)
    {
        return (unsigned char)std::max(0.0f, std::min(255.0f, value * 255.0f));// + 0.5f));
    }

    PPM_Image::PPM_Image(const std::string& fileName)
        : _fileName(fileName)
    {
    }

    void PPM_Image::Save(const Table<ColorRGB>& image)
    {
        std::ofstream file(_fileName, std::ios::out | std::ios::binary);

        const size_t width = image.GetWidth();
        const size_t height = image.GetHeight();

        file << "P6\n" << width << " " << height << "\n255\n";

        for (size_t row = 0; row < height; ++row)
        {
            for (size_t column = 0; column < width; ++column)
            {
                ColorRGB pixel = image.Get(row, column);

                unsigned char red = ConvertToUnsignedChar(pixel.Red);
                unsigned char green = ConvertToUnsignedChar(pixel.Green);
                unsigned char blue = ConvertToUnsignedChar(pixel.Blue);

                file << red << green << blue;
            }
        }

        file.close();
    }
}
