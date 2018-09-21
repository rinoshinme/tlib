#include "counter.h"

namespace tlib
{
    Counter::Counter()
    {
        m_map.clear();
    }
    
    void Counter::add(const std::string& name, int cnt)
    {
        if (m_map.find(name) == m_map.end())
            m_map[name] = 0;
        m_map[name] += cnt;
    }
    
    int Counter::get(const std::string &name)
    {
        if (m_map.find(name) == m_map.end())
            return 0;
        else
            return m_map[name];
    }
    
    
}
