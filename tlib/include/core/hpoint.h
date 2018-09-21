#ifndef tlib_hpoint_h
#define tlib_hpoint_h

namespace tlib
{
    template<typename T>
    struct HPoint2d
    {
        T x;
        T y;
        T w;
    };
    
    template<typename T>
    struct HPoint3d
    {
        T x;
        T y;
        T z;
        T w;
    };
}

#endif /* tlib_hpoint_h */
