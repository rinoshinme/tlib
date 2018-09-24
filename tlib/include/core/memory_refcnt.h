#ifndef tlib_memory_refcnt_h
#define tlib_memory_refcnt_h

#include <cstdlib>

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
        
        MemoryWithRefCount(int s = 64)
        {
            size = s;
            data = new T[size];
            memset(data, 0, sizeof(T) * size);
            ref_cnt = 1;
        }
        
        ~MemoryWithRefCount()
        {
            ref_cnt -= 1;
            if (ref_cnt == 0)
            {
                delete[] data;
                data = NULL;
            }
        }
        
        MemoryWithRefCount MakePrivate()
        {
            if (ref_cnt == 1)
                return (*this);
            else
            {
                MemoryWithRefCount new_memory(size);
                memcpy(new_memory.data, data, sizeof(T) * size);
                ref_cnt -= 1;
                return new_memory;
            }
        }
    };
}

#endif /* tlib_memory_refcnt_h */
