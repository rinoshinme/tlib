#include "logger.h"

namespace tlib
{
    Logger::Logger(const std::string& name, int fd)
    {
        m_name = name;
        m_fd = fd;
    }
    
    void Logger::write(const std::string& msg)
    {
        char buf[1024];
        time_t tt = time(NULL);
        struct tm* local_time = localtime(&tt);
        char time_buf[64];
        strftime(time_buf, 64, "%G%m%d-%H:%M:%S", local_time);
        sprintf(buf, "[%s]-[%s] %s\n", time_buf,  m_name.c_str(), msg.c_str());
        ::write(m_fd, buf, strlen(buf));
    }
}
