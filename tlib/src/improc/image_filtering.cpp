#include "image_filtering.h"

namespace tlib
{
    Filter::Filter(const std::vector<float>& k, int dir)
    {
        if (dir == 0)
        {
            m_xKernel = k;
            m_filterType = FilterType::FILTER_ROW;
        }
        else
        {
            m_yKernel = k;
            m_filterType = FilterType::FILTER_COL;
        }
    }
    
    Filter::Filter(const std::vector<float>& kx, const std::vector<float>& ky)
    {
        m_xKernel = kx;
        m_yKernel = ky;
        m_filterType = FilterType::FILTER_SEPARABLE;
    }
    
    Filter::Filter(const std::vector<std::vector<float> >& kxy)
    {
        m_kernel = kxy;
        m_filterType = FilterType::FILTER_NONSEPARABLE;
    }
    
    
    
}
