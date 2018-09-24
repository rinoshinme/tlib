#ifndef tlib_perceptron_h
#define tlib_perceptron_h

#include "array.h"

namespace tlib
{
    // perceptron algorithm
    class Perceptron
    {
    private:
        Array<float> m_weights;
        Array<float> m_bias;
    public:
        // initialize weights and bias with random number
        Perceptron(bool randomize = true);
        
        void update(const Array<float>& batch_x, const Array<float>& batch_y);
    };
}

#endif /* tlib_perceptron_h */
