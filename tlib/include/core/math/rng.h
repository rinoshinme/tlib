#ifndef tlib_rng_h
#define tlib_rng_h

#include <vector>

namespace tlib
{
    /*
     * static functions for generating random numbers
     */
    class RNG
    {
    public:
        static float getFloat();
        static int getInt();
        static bool getBool();
        static std::vector<float> getFloatVec();
        
        template<typename T>
        static Array<T> getArray(const std::vector<int>& shape);
    };
}

#endif /* tlib_rng_h */
