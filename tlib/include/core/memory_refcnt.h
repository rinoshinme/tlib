#ifndef tlib_memory_refcnt_h
#define tlib_memory_refcnt_h

#include <cstdlib>

namespace tlib
{
    /*
     * internal representation of a memory buffer
     * simple
     */
    template<typename T>
    struct MemoryWithRefCount
    {
    public:
        T* data;
        int size;
        int refCnt;
        
    public:
        MemoryWithRefCount()
        {
            data = NULL;
            size = 0;
            refCnt = 1;
        }
        
        MemoryWithRefCount(int length)
        {
            size = length;
            data = new T[size];
            memset(data, 0, sizeof(T) * size);
            refCnt = 1;
        }
        
        ~MemoryWithRefCount()
        {
            refCnt -= 1;
            if (refCnt == 0)
            {
                delete[] data;
                data = NULL;
            }
        }
        
        void create(int new_size)
        {
            // ref cnt not modified
            if (data != NULL)
                delete[] data;
            data = new T[new_size];
            size = new_size;
        }
        
        MemoryWithRefCount MakePrivate()
        {
            if (refCnt == 1)
                return (*this);
            else
            {
                MemoryWithRefCount new_memory(size);
                memcpy(new_memory.data, data, sizeof(T) * size);
                refCnt -= 1;
                return new_memory;
            }
        }
        
        void incRefCount() { refCnt += 1; }
        void decRefCount() { refCnt -= 1; }
        int getRefCount() const { return refCnt; }
        
        int getSize() const { return size; }
        T* getData() { return data; }
        const T* getData() const { return data; }
        
    private:
        MemoryWithRefCount(const MemoryWithRefCount& copy) {}
        MemoryWithRefCount& operator=(const MemoryWithRefCount& copy) {}
    };
}

#endif /* tlib_memory_refcnt_h */
