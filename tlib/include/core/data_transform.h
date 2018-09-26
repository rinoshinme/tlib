#ifndef tlib_data_io_h
#define tlib_data_io_h

#include "array.h"
#include "image.h"
#include <string>

namespace tlib
{
    void readText(const std::string& txt_file, Array<float>& array, char sep = ',');
    void readText(const std::string& txt_file, Array<float>& data, Array<int>& label, char sep = ',');
    void read
}

#endif /* tlib_data_io_h */
