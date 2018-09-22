#ifndef tlib_image_filtering_h
#define tlib_image_filtering_h

#include <vector>

namespace tlib
{
    enum FilterType
    {
        FILTER_SEPARABLE,
        FILTER_NONSEPARABLE,
        FILTER_NOLINEAR
    };
    
    // image filtering
    class Filter
    {
    private:
        std::vector<float> m_xKernel;
        std::vector<float> m_yKernel;
        std::vector<std::vector<float> > m_kernel;
        FilterType m_filterType;
        
    public:
        Filter();
        Filter(const Filter& other);
        Filter& operator=(const Filter& other);
        static Filter getMeanFilter;
        static Filter getGaussianFilter;
        
    public:
        
        
    };
}

#endif /* tlib_image_filtering_h */
