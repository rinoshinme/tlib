#ifndef tlib_vector_h
#define tlib_vector_h

namespace tlib
{
    template<typename T, int Size>
    class Vector
    {
        T m_data[Size];
    public:
        Vector(T val = T());
        
        T& operator[](int idx) { return m_data[idx]; }
        const T& operator[](int idx) const { return m_data[idx]; }
        
    public:
        static Vector<T, Size> ones();
        static Vector<T, Size> zeros();
    };
}

#endif /* tlib_vector_h */
