#ifndef tlib_rect_h
#define tlib_rect_h

#include "point.h"
#include <cassert>

#ifndef MIN
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#endif
#ifndef MAX
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#endif


namespace tlib
{
    template<typename T>
    struct Rect
    {
        T x;
        T y;
        T width;
        T height;

        Rect(T px = 0, T py = 0, T w = 0, T h = 0)
        :x(px), y(py), width(w), height(h) {}
        
        bool isValid() { return (width > 0) && (height > 0); }
        
        bool contains(const Point2d<T>& point)
        {
            bool id_x = (point.x > x) && (point.x < x + width);
            bool id_y = (point.y > y) && (point.y < y + height);
            return (id_x && id_y);
        }
        
        Point2d<T> center() const
        {
            Point2d<T> pt;
            pt.x = x + width / 2;
            pt.y = y + height / 2;
            return pt;
        }
        
        double area() const { return width * height; }
        
        Rect intersect(const Rect<T>& rect)
        {
            T min_x = MAX(x, rect.x);
            T min_y = MAX(y, rect.y);
            T max_x = MIN(x + width, rect.x + rect.width);
            T max_y = MIN(y + height, rect.y + rect.height);
            
            if ((min_x >= max_x) || (min_y >= max_y))
                return Rect<T>();
            else
                return Rect<T>(min_x, min_y, max_x - min_x, max_y - min_y);
        }
        
        double iou(const Rect<T>& rect)
        {
            assert(rect.isValid() && isValid());
            
            Rect cross = intersect(rect);
            return cross.area() * 1.0 / (area() * rect.area());
        }
    };
}

#endif /* tlib_rect_h */
