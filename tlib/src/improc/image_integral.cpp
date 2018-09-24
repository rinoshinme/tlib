#include "image_integral.h"

namespace tlib
{
    ImageIntegral::ImageIntegral(const Image<float>& image)
    {
        m_width = image.width();
        m_height = image.height();
        m_channels = image.channels();
        m_data = new float[m_width * m_height * m_channels];
        for (int c = 0; c < m_channels; ++c)
        {
            // initialize border items
            for (int x = 0; x < m_width; ++x)
            {
                for (int y = 0; y < m_height; ++y)
                {
                    
                }
            }
        }
    }
}
