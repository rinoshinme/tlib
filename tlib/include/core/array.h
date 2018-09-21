#ifndef tlib_array_h
#define tlib_array_h

#include <vector>

namespace tlib
{
    /*
     * internal representation of a memory buffer
     */
    template<typename T>
    struct MemoryWithRefCount
    {
        T* data;
        int size;
        int ref_cnt;
        
        MemoryWithRefCount(int s = 64);
        ~MemoryWithRefCount();
        MemoryWithRefCount MakePrivate() const;
    };
    
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
        Array(int n, int c, int h, int w);
        Array(const std::vector<int>& shape); // shape of
        Array(const Array<T>& source);
        Array<T>& operator=(const Array<T>& source);
        ~Array();
        
        void copyFrom(const Array<T>& source);
        
    private:
        int offset(int n, int c, int h, int w);
        int offset(const std::vector<int>& indices);
        
    };
}

#endif /* tlib_array_h */
