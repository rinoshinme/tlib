#ifndef tlib_logistic_regression_h
#define tlib_logistic_regression_h

#include "array.h"

namespace tlib
{
    // logistic regression
    class LogisticRegressionModel
    {
    private:
        // internal weights
        Array<float> m_weights;
        float m_bias;
        bool m_withBias;
        
    public:
        LogisticRegressionModel(bool withBias = true);
        
    };
}

#endif /* tlib_logistic_regression_h */
