#ifndef tlib_image_integral_h
#define tlib_image_integral_h

#include "image.h"

namespace tlib
{
    /* channel-wise integral image */
    class ImageIntegral : public Image<float>
    {
    public:
        ImageIntegral(const Image<float>& image);
        ~ImageIntegral();
        
        float getRectSum(int left, int right, int top, int bottom);
        
    private:
        void contruct();
    };
}

#endif /* tlib_image_integral_h */
