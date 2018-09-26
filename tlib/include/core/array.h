#ifndef tlib_array_h
#define tlib_array_h

#include "memory_refcnt.h"
#include <vector>

namespace tlib
{
    /*
     * dynamic 4d array
     */
    template<typename T>
    class Array
    {
    private:
        MemoryWithRefCount<T>* m_data;
        std::vector<int> m_shape;
        std::vector<int> m_strides;
        std::vector<int> m_starts;
        
    public:
        Array() { m_data = NULL; }
        Array(int n, int c, int h, int w)
        {
            int size = n * c * h * w;
            m_data = new MemoryWithRefCount<T>(size);
            
            m_shape.push_back(n);
            m_shape.push_back(c);
            m_shape.push_back(h);
            m_shape.push_back(w);
            
            m_strides.push_back(w * h * c);
            m_strides.push_back(w * h);
            m_strides.push_back(w);
            m_strides.push_back(1);
            
            m_starts = std::vector<int>{0, 0, 0, 0};
        }
        
        Array(const std::vector<int>& shape)
        {
            int size = 1;
            for (size_t k = 0; k < shape.size(); ++k)
                size += shape[k];
            m_data = new MemoryWithRefCount<T>(size);
            
            m_shape = shape;
            
            m_strides.push_back(m_shape[3] * m_shape[2] * m_shape[1]);
            m_strides.push_back(m_shape[3] * m_shape[2]);
            m_strides.push_back(m_shape[3]);
            m_strides.push_back(1);
            
            m_starts = std::vector<int>{0, 0, 0, 0};
        }
        
        Array(const Array<T>& source)
        {
            m_data = source.m_data;
            m_shape = source.m_shape;
            m_strides = source.m_strides;
            m_data->incRefCount();
        }
        
        Array<T>& operator=(const Array<T>& source)
        {
            delete m_data;
            m_data = source.m_data;
            m_data->incRefCount();
            m_shape = source.m_shape;
            m_strides = source.m_strides;
            m_starts = source.m_starts;
        }
        
        ~Array()
        {
            m_data->decRefCount();
            if (m_data->getRefCount() == 0)
                delete m_data;
        }
        
        /* deep copy from source */
        void copyFrom(const Array<T>& source)
        {
            int size = source.m_data->size;
            m_data = new MemoryWithRefCount<T>(size);
            // copy data
            memcpy(m_data->data, source.m_data.data, size * sizeof(T));
            m_shape = source.m_shape;
            m_strides = source.m_strides;
            m_starts = source.m_starts;
        }
        
        Array<T> getSubarray(const std::vector<int>& shape, const std::vector<int>& starts)
        {
            Array<T> result;
            result.m_data = m_data;
            m_data->incRefCount();
            result.m_shape = shape;
            result.m_strides = m_strides;
            result.m_starts = m_starts;
            for (int i = 0; i < 4; ++i)
                result.m_starts[i] += starts[i];
            return result;
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
        
        int getDataRefCount() const { return m_data->getRefCount(); }
        
        void reshape(int n, int c, int h, int w);
        void reshape(const std::vector<int>& shape);
    public:
        int offset(int n, int c, int h, int w)
        {
            int idx = 0;
            idx += (n + m_starts[0]) * m_strides[0];
            idx += (c + m_starts[1]) * m_strides[1];
            idx += (h + m_starts[2]) * m_strides[2];
            idx += (w + m_starts[3]) * m_strides[3];
            return idx;
         }
        
        int offset(const std::vector<int>& indices)
        {
            int idx = 0;
            for (int i = 0; i < 4; ++i)
                idx += (indices[i] + m_starts[i]) * m_strides[i];
            return idx;
        }
        
    };
}

#endif /* tlib_array_h */
