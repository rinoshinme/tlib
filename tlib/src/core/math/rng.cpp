#include "rng.h"

namespace tlib
{
    RNG* RNG::getRNG(int* seed)
    {
        if (seed)
            srand(*seed);
        else
            srand((unsigned int)time(NULL));
        
        RNG* rng = new RNG;
        return rng;
    }
    
    void RNG::destroyRNG(RNG** rng)
    {
        delete *rng;
        *rng = NULL;
    }
    
    float RNG::getFloat()
    {
        int value = rand();
        return (value * 1.0f) / RAND_MAX;
    }
    
    int RNG::getInt(int xmin, int xmax)
    {
        int value = rand();
        return (value % (xmax - xmin)) + xmin;
    }
    
    bool RNG::getBool(float prob1)
    {
        float value = getFloat();
        return (value < prob1) ? true : false;
    }
    
    std::vector<float> RNG::getFloatVec(int numSamples)
    {
        std::vector<float> result(numSamples);
        for (int i = 0; i < numSamples; ++i)
            result[i] = getFloat();
        return result;
    }
    
}
