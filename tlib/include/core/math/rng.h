#ifndef tlib_rng_h
#define tlib_rng_h

#include "array.h"
#include <vector>

namespace tlib
{
    /*
     * static functions for generating random numbers
     */
    class RNG
    {
    private:
        ssize_t seed;
    public:
        // singleton pattern
        static RNG getRNG(int* seed = NULL)
        {
            return RNG();
        }
        
    public:
        float getFloat();
        int getInt();
        bool getBool();
        std::vector<float> getFloatVec();
        
        template<typename T>
        Array<T> getArray(const std::vector<int>& shape);
        
    private:
        RNG() {}
        RNG(const RNG& other) {}
        // RNG& operator=(const RNG& other)
        ~RNG() {}
    };
}

#endif /* tlib_rng_h */
