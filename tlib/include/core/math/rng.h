#ifndef tlib_rng_h
#define tlib_rng_h

#include "array.h"
#include <vector>
#include <cstdlib>
#include <ctime>

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
        static RNG* getRNG(int* seed = NULL);
        
        static void destroyRNG(RNG** rng);
    public:
        float getFloat();
        int getInt(int xmin, int xmax);
        bool getBool(float prob1);
        std::vector<float> getFloatVec(int numSamples);
        
        template<typename T>
        Array<T> getArray(const std::vector<int>& shape)
        {
            Array<T> result(shape);
            int length = result.length();
            for (int i = 0; i < length; ++i)
                result.setData(i, getFloat());
            return result;
        }
        
    private:
        RNG() {}
        RNG(const RNG& other) {}
        // RNG& operator=(const RNG& other)
        ~RNG() {}
    };
}

#endif /* tlib_rng_h */
