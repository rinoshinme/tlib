#ifndef tlib_image_h
#define tlib_image_h

#include <string>

namespace tlib
{
    /*
     * 3d image representation
     */
    template<typename T>
    class Image
    {
        T* m_data;
        int m_width;
        int m_height;
        int m_channels;
    public:
        Image(int w, int h, int c = 1)
        {
            m_width = w;
            m_height = h;
            m_channels = c;
            int length = m_width * m_height * m_channels;
            m_data = new T[length];
            memset(m_data, 0, length * sizeof(T));
        }
        
        ~Image()
        {
            if (m_data != NULL)
                delete[] m_data;
        }
        
        int width() const { return m_width; }
        int height() const { return m_height; }
        int channels() const { return m_channels; }
        
        T* dataPtr();
        const T* dataPtr() const;
        T* rowPtr();
        const T* rowPtr() const;
        T& operator()(int x, int y);
        T& operator()(int x, int y, int z);
        const T& operator()(int x, int y) const;
        const T& operator()(int x, int y, int z) const;
        
        // operator overloadings
        
        // void load(const std::string& file_path);
        // void save(const std::string& file_path);
    };
}

#endif /* tlib_image_h */
