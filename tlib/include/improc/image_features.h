#ifndef tlib_image_features_h
#define tlib_image_features_h

#include "../core/point.h"
#include "../core/image.h"

namespace tlib
{
    struct HarrisFeature;
    
    // functions for generating features
    std::vector<HarrisFeature> harris(const Image<float>& image);
    void canny(const Image<float>& image, Image<float>& edge);
    void sift();
    void lbp();
    void fast();
    
    
    // implementation details
    struct HarrisFeature
    {
        Point2d<int> position;
        float value;
    };
    
    class CannyFeature
    {
    private:
        // 
    };
    
    
}

#endif /* tlib_image_features_h */
