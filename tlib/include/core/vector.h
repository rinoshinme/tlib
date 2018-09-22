#ifndef tlib_vector_h
#define tlib_vector_h

namespace tlib
{
    template<typename T, int Size>
    class Vector
    {
        T m_data[Size];
    public:
        Vector(T val = T())
        {
            for (int i = 0; i < Size; ++i)
                m_data[i] = val;
        }
        
        Vector(T* data)
        {
            for (int i = 0; i < Size; ++i)
                m_data[i] = data[i];
        }
        
        Vector(const Vector<T, Size>& other)
        {
            for (int i = 0; i < Size; ++i)
                m_data[i] = other.m_data[i];
        }
        
        Vector<T, Size>& operator=(const Vector<T, Size>& other)
        {
            for (int i = 0; i < Size; ++i)
                m_data[i] = other.m_data[i];
            return *this;
        }
        
        T& operator[](int idx) { return m_data[idx]; }
        const T& operator[](int idx) const { return m_data[idx]; }
        
        std::string toString() const
        {
            char buf[1024];
            int pos = 0;
            pos += sprintf(buf + pos, "[");
            for (int i = 0; i < Size - 1; ++i)
                pos += sprintf(buf + pos, "%s, ", m_data[i]);
            pos += sprintf(buf + pos, "%s]", m_data[Size - 1]);
            return std::string(buf);
        }
        
    public:
        static Vector<T, Size> ones()
        {
            Vector<T, Size> result;
            for (int i = 0; i < Size; ++i)
                result.m_data[i] = 1;
            return result;
        }
        
        static Vector<T, Size> zeros()
        {
            Vector<T, Size> result;
            for (int i = 0; i < Size; ++i)
                result.m_data[i] = 0;
            return result;
        }
        
        Vector<T, Size> operator+(const Vector<T, Size>& other)
        {
            Vector<T, Size> result;
            for (int i = 0; i < Size; ++i)
                result.m_data[i] = m_data[i] + other.m_data[i];
            return result;
        }
        
        Vector<T, Size> operator-(const Vector<T, Size>& other)
        {
            Vector<T, Size> result;
            for (int i = 0; i < Size; ++i)
                result.m_data[i] = m_data[i] - other.m_data[i];
            return result;
        }
        
        Vector<T, Size> operator+(const T other)
        {
            Vector<T, Size> result;
            for (int i = 0; i < Size; ++i)
                result.m_data[i] = m_data[i] + other;
            return result;
        }
        
        Vector<T, Size> operator-(const T other)
        {
            Vector<T, Size> result;
            for (int i = 0; i < Size; ++i)
                result.m_data[i] = m_data[i] - other;
            return result;
        }
        
        Vector<T, Size> operator*(const T other)
        {
            Vector<T, Size> result;
            for (int i = 0; i < Size; ++i)
                result.m_data[i] = m_data[i] * other;
            return result;
        }
        
        Vector<T, Size> operator/(const T other)
        {
            Vector<T, Size> result;
            for (int i = 0; i < Size; ++i)
                result.m_data[i] = m_data[i] / other;
            return result;
        }
        
        T dot(const Vector<T, Size>& other)
        {
            T sum = 0;
            for (int i = 0; i < Size; ++i)
                sum += m_data[i] * other.m_data[i];
            return sum;
        }
    };
    
    // cross product for dim3 vectors
    template<typename T>
    Vector<T, 3> cross(const Vector<T, 3>& vec1, const Vector<T, 3>& vec2)
    {
        Vector<T, 3> result;
        result[0] = vec1[1] * vec2[2] - vec1[2] * vec2[1];
        result[1] = vec1[2] * vec2[0] - vec1[0] * vec2[2];
        result[2] = vec1[0] * vec2[1] - vec1[1] * vec2[0];
        return result;
    }
}

#endif /* tlib_vector_h */
