#ifndef tlib_signal_h
#define tlib_signal_h

namespace tlib
{
    // signal channel 1 dimensional signal
    template<typename T>
    struct Signal
    {
    private:
        T* data;
        int size;
        
    public:
        Signal(int len)
        {
            size = len;
            data = new T[size];
            memset(data, 0, size * sizeof(T));
        }
        
        Signal(T* source, int len)
        {
            size = len;
            data = new T[size];
            memcpy(data, source, size * sizeof(T));
        }
        
        Signal(const std::vector<T>& vec)
        {
            size = vec.size();
            data = new T[size];
            memcpy(data, &vec[0], size * sizeof(T));
        }
        
        ~Signal()
        {
            if (data != NULL)
                delete[] data;
        }
        
        T& operator[](int index) { return data[index]; }
        const T& operator[](int index) const { return data[index]; }
    };
}


#endif /* tlib_signal_h */
