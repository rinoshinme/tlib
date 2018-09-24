#ifndef tlib_sound_io_h
#define tlib_sound_io_h

#include "../core/sound.h"

namespace tlib
{
    //
    bool wavRead(const std::string& filename, Sound<float>& sound);
    bool wavWrite(const std::string& filename, const Sound<float>& sound);
}

#endif /* tlib_sound_io_h */
