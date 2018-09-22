#ifndef tlib_image_features_h
#define tlib_image_features_h

#include "../core/point.h"
#include "../core/image.h"

namespace tlib
{
    // functions for generating features
    struct HarrisFeature
    {
        Point2d<int> position;
        float value;
    };
    
    std::vector<HarrisFeature> getHarrisFeature(const Image<float>& image);
}

#endif /* tlib_image_features_h */
