#ifndef tlib_batch_h
#define tlib_batch_h

#include "array.h"

namespace tlib
{
    // generate batch of examples
    // internally, data is replicated twice to support non-integer batch number per epoch
    template<typename TInput, typename TOutput>
    class BatchGenerator
    {
    private:
        Array<TInput> m_samples;
        Array<TOutput> m_labels;
        int m_numSamples;
        
    public:
        BatchGenerator() {}
        BatchGenerator(const Array<TInput>& samples, const Array<TOutput>& labels)
        {
            // data is deeply copied
        }
        
        ~BatchGenerator() {}
        
        void loadData(const Array<TInput>& samples, const Array<TOutput>& labels);
        
        // batch size should be less than number of samples
        std::pair<Array<TInput>, Array<TOutput> > batch(int batch_size);
    };
}

#endif /* batch_h */
