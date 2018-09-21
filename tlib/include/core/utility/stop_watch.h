#ifndef tlib_stop_watch_h
#define tlib_stop_watch_h

#include <ctime>
#include <string>
#include <utility>
#include <vector>

namespace tlib
{
    class StopWatch
    {
    private:
        clock_t m_start;
        clock_t m_end;
        std::vector<std::pair<std::string, clock_t> > m_time_map;
        
    public:
        StopWatch();
        
        void start();
        void click(const std::string& stamp);
        void stop();
        
        clock_t getTimeCost(int index);
        clock_t getTimeCost(const std::string& name);
        size_t getNum() const { return m_time_map.size(); }
    };
}

#endif /* tlib_stop_watch_h */
