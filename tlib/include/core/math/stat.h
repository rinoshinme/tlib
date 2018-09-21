#ifndef tlib_stat_h
#define tlib_stat_h

#include <vector>

namespace tlib
{
    /* statistics functions */
    double mean(const std::vector<double>& data);
    double median(const std::vector<double>& data);
    double variance(const std::vector<double>& data);
    
}

#endif /* tlib_stat_h */
