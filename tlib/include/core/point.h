#ifndef tlib_point_h
#define tlib_point_h

namespace tlib
{
    template<typename T>
    struct Point2d
    {
        T x;
        T y;
        Point2d(T px = 0, T py = 0)
        : x(px), y(py) {}
        
        double distToOrigin() const;
        double distTo(const Point2d<T>& other) const;
    };
    
    template<typename T>
    struct Point3d
    {
        T x;
        T y;
        T z;
        Point3d(T px = 0, T py = 0, T pz = 0)
        : x(px), y(py), z(pz) {}
        
        double distToOrigin() const;
        double distTo(const Point3d<T>& other) const;
    };
}

#endif /* tlib_point_h */
