#ifndef tlib_colors_h
#define tlib_colors_h

namespace tlib
{
    struct RGB
    {
        float red;
        float green;
        float blue;
    };
    
    struct RGBA
    {
        float red;
        float green;
        float blue;
        float alpha;
    };
    
    struct HSV
    {
        float hue;
        float saturation;
        float value;
    };
    
    struct Lab
    {
        float L;
        float a;
        float b;
    };
    
}

#endif /* tlib_colors_h */
