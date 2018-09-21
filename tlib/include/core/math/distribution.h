#ifndef tlib_distribution_h
#define tlib_distribution_h

#include "rng.h"

namespace tlib
{
    /* generate random distributions */
    float uniform();
    float gaussian();
    float poisson();
}

#endif /* tlib_distribution_h */
