#ifndef tlib_counter_h
#define tlib_counter_h

#include <map>
#include <string>

namespace tlib
{
    class Counter
    {
    private:
        std::map<std::string, int> m_map;
    public:
        Counter();
        void add(const std::string& name, int cnt = 1);
        int get(const std::string& name);
    };
}

#endif /* tlib_counter_h */
