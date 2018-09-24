#ifndef tlib_image_io_h
#define tlib_image_io_h

#include "image.h"
#include <string>

namespace tlib
{
    // image io functions
    bool bmpRead(const std::string& filename, Image<float>& image);
    bool bmpWrite(const std::string& filename, Image<float>& image);
    
}

#endif /* tlib_image_io_h */
