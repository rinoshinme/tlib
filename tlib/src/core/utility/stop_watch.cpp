#include "stop_watch.h"

namespace tlib
{
    StopWatch::StopWatch()
    {
        m_start = 0;
        m_end = 0;
        m_time_map.clear();
    }
    
    void StopWatch::start()
    {
        m_start = clock();
    }
    
    void StopWatch::stop()
    {
        m_end = clock();
    }
    
    void StopWatch::click(const std::string &stamp)
    {
        clock_t now = clock();
        m_time_map.push_back(std::make_pair(stamp, now - m_start));
    }
    
    clock_t StopWatch::getTimeCost(int index)
    {
        return m_time_map[index].second;
    }
    
    clock_t StopWatch::getTimeCost(const std::string& name)
    {
        for (size_t k = 0; k < m_time_map.size(); ++k)
        {
            if (m_time_map[k].first == name)
                return m_time_map[k].second;
        }
        return 0;
    }
    
}

