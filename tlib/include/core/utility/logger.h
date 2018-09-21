#ifndef tlib_logger_h
#define tlib_logger_h

#include <string>
#include <ctime>
#include <unistd.h>
#include <stdio.h>

namespace tlib
{
    class Logger
    {
    private:
        std::string m_name;
        int m_fd;
        FILE* fp;
        
    public:
        Logger(const std::string& name, int fd = STDOUT_FILENO);
        void write(const std::string& msg);
    };
}

#endif /* tlib_logger_h */
