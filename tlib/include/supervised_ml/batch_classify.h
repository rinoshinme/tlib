#ifndef tlib_batch_classify_h
#define tlib_batch_classify_h

#include "batch.h"
#include "array.h"
#include <utility>

namespace tlib
{
    class BatchGeneratorClassification
    {
    private:
        Array<float> m_samples;
        Array<int> m_labels;
        
    public:
        BatchGeneratorClassification();
        BatchGeneratorClassification(const Array<float>& samples, const Array<float>& labels);
        
        void loadData(const Array<float>& samples, const Array<float>& labels);
        std::pair<Array<float>, Array<float> > batch(int batch_size);
    };
}

#endif /* tlib_batch_classify_h */
