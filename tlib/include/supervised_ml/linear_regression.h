#ifndef tlib_linear_regression_h
#define tlib_linear_regression_h

#include "array.h"

namespace tlib
{
    // linear regression
    class LinearRegressionModel
    {
    private:
        Array<float> m_weights;
        float m_bias;
        bool m_withBias;
    public:
        LinearRegressionModel(bool withBias);
        
    };
}

#endif /* tlib_linear_regression_h */
