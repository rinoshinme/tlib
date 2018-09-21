#ifndef tlib_rect_h
#define tlib_rect_h

#include "point.h"

namespace tlib
{
    template<typename T>
    struct Rect
    {
        T x;
        T y;
        T width;
        T height;
        
        Rect();
        Rect(T px, T py, T w, T h);
        
        bool contains(const Point2d<T>& point)
        {
            bool id_x = (point.x > x) && (point.x < x + width);
            bool id_y = (point.y > y) && (point.y < y + height);
            return id_x && id_y;
        }
        
        Point2d<T> center() const
        {
            Point2d<T> pt;
            pt.x = x + width / 2;
            pt.y = y + height / 2;
            return pt;
        }
        
        double area() const { return width * height; }
        
        Rect intersect(const Rect<T>& rect);
        
        double iou(const Rect<T>& rect);
    };
}

#endif /* tlib_rect_h */
