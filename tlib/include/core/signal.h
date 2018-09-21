#ifndef tlib_signal_h
#define tlib_signal_h

namespace tlib
{
    template<typename T>
    struct Signal
    {
        T* data;
        int size;
        
        Signal(int len);
        ~Signal();
    };
}


#endif /* tlib_signal_h */
