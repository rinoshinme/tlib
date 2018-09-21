#ifndef tlib_rect_h
#define tlib_rect_h

namespace tlib
{
    template<typename T>
    struct Rect
    {
        T x;
        T y;
        T width;
        int height;
    };
}

#endif /* tlib_rect_h */
