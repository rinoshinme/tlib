#ifndef tlib_array_h
#define tlib_array_h

#include "memory_refcnt.h"
#include <vector>

namespace tlib
{
    /*
     * dynamic array
     */
    template<typename T>
    class Array
    {
    private:
        MemoryWithRefCount<T>* m_data;
        std::vector<int> m_shape;
        std::vector<int> m_start;
        
    public:
        Array()
        {
            m_data = NULL;
            m_shape.clear();
            m_start.clear();
        }
        
        Array(int n, int c, int h, int w)
        {
            int size = n * c * h * w;
            m_data = new MemoryWithRefCount<T>(size);
            m_shape.push_back(n);
            m_shape.push_back(c);
            m_shape.push_back(h);
            m_shape.push_back(w);
            
            for (int i = 0; i < 4; ++i)
                m_start.push_back(0);
        }
        
        Array(const std::vector<int>& shape) // shape of
        {
            int size = 1;
            for (size_t k = 0; k < shape.size(); ++k)
                size += shape[k];
            m_data = new MemoryWithRefCount<T>(size);
            m_shape = shape;
            for (size_t i = 0; i < shape.size(); ++i)
                m_start.push_back(0);
        }
        
        Array(const Array<T>& source)
        {
            m_data = source.m_data;
            m_shape = source.m_shape;
            m_start = source.m_start;
            m_data->ref_cnt += 1;
        }
        
        Array<T>& operator=(const Array<T>& source)
        {
            delete m_data;
            m_data = source.m_data;
            m_data->ref_cnt += 1;
            m_shape = source.m_shape;
            m_start = source.m_start;
        }
        
        ~Array()
        {
            delete m_data;
        }
        
        int length() const
        {
            int length = 1;
            for (size_t i = 0; i < m_shape.size(); ++i)
                length *= m_shape[i];
            return length;
        }
        
        int dataSize() const
        {
            return length() * sizeof(T);
        }
        
        void setData(int index, T value)
        {
            m_data->data[index] = value;
        }
        
        void setData(const T* data_source)
        {
            memcpy(m_data->data, data_source, m_data->size * sizeof(T));
        }
        
        /* deep copy from source */
        void copyFrom(const Array<T>& source)
        {
            int size = source.m_data->size;
            m_data = new MemoryWithRefCount<T>(size);
            m_shape = source.m_shape;
            m_start = source.m_start;
        }
        
        void reshape(int n, int c, int h, int w);
        void reshape(const std::vector<int>& shape);
        
        Array<T> getSubarray(const std::vector<int>& shape, const std::vector<int>& starts);
        
    private:
        int offset(int n, int c, int h, int w)
        {
            int idx = 0;
            idx = idx + n + m_start[0];
            idx = idx * m_shape[0] + c + m_start[1];
            idx = idx * m_shape[1] + h + m_start[2];
            idx = idx * m_shape[2] + w + m_start[3];
            return idx;
         }
        
        int offset(const std::vector<int>& indices)
        {
            int idx = 0;
            for (int i = 0; i < 4; ++i)
            {
                idx = idx * m_shape[i] + indices[i] + m_start[i];
            }
            return idx;
        }
        
    };
}

#endif /* tlib_array_h */
