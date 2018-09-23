#ifndef tlib_image_integral_h
#define tlib_image_integral_h

#include "image.h"

namespace tlib
{
    /* channel-wise integral image */
    class ImageIntegral
    {
    private:
        float* m_data;
        int m_width;
        int m_height;
        int m_channel;
        
    public:
        ImageIntegral(const Image<float>& image);
        
        float getRectSum(int left, int right, int top, int bottom);
        
    private:
        void contruct();
    };
}

#endif /* tlib_image_integral_h */
