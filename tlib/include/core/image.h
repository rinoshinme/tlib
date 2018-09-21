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
        Image(int w, int h, int c);
        ~Image();
        
        int width() const;
        int height() const;
        int channels() const;
        
        void load(const std::string& file_path);
        void save(const std::string& file_path);
    };
}

#endif /* tlib_image_h */
