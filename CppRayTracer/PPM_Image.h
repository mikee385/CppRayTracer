#ifndef PPM_IMAGE_HEADER_GUARD
#define PPM_IMAGE_HEADER_GUARD

#include "ColorRGB.h"
#include "Table.h"
#include <string>

class PPM_Image
{
private:
    std::string _fileName;

public:
    PPM_Image(const std::string& fileName);

    void Save(const Table<ColorRGB>& image);
};

#endif
