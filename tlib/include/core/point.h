#ifndef tlib_point_h
#define tlib_point_h

namespace tlib
{
    template<typename T>
    struct Point2d
    {
        T x;
        T y;
    };
    
    template<typename T>
    struct Point3d
    {
        T x;
        T y;
        T z;
    };
}

#endif /* tlib_point_h */
