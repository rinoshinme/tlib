#ifndef tlib_image_filtering_h
#define tlib_image_filtering_h

#include "image.h"
#include <vector>

namespace tlib
{
    enum FilterType
    {
        FILTER_ROW,
        FILTER_COL,
        FILTER_SEPARABLE,
        FILTER_NONSEPARABLE,
        // FILTER_NOLINEAR
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
        Filter(const std::vector<float>& k, int dir);
        Filter(const std::vector<float>& kx, const std::vector<float>& ky);
        Filter(const std::vector<std::vector<float> >& kxy);
        
        static Filter getMeanFilter();
        static Filter getGaussianFilter();
        
    public:
        void apply(const Image<float>& input, Image<float>& output);
        
        void applyX();
        void applyXTranspose();
        void applyY();
        void applyYTranspose();
        void applyXY();
        
        
    };
}

#endif /* tlib_image_filtering_h */
