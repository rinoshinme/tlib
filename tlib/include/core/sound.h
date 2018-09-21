#ifndef tlib_sound_h
#define tlib_sound_h

#include "signal.h"

namespace tlib
{
    template<typename T>
    class Sound
    {
    private:
        Signal<T>* m_left;
        Signal<T>* m_right;
        int m_nChannels;
    public:
        Sound();
        ~Sound();
        
    };
}

#endif /* tlib_sound_h */
