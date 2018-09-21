#ifndef tlib_stop_watch_h
#define tlib_stop_watch_h

#include <ctime>
#include <string>
#include <utility>

namespace tlib
{
    class StopWatch
    {
    private:
        clock_t m_start;
        clock_t m_end;
        std::vector<std::pair<std::string, clock_t> > time_map;
        
    public:
        StopWatch();
        
        void start();
        void click(const std::string& stamp);
        void stop();
    };
}

#endif /* tlib_stop_watch_h */
