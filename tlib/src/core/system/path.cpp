#include "path.h"
#include "stringops.h"
#include <iostream>

#if defined(__APPLE__)
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#else
#include <io.h>
#endif

namespace tlib
{
    Path::Path(const std::string& path_name)
    {
        splitPath(path_name, m_folders, m_file);
#if defined(__APPLE__)
        m_sep = '/';
#else
        m_sep = '\\';
#endif
        
#if 0
        // output path
        for (size_t k = 0; k < m_folders.size(); ++k)
            std::cout << m_folders[k] << std::endl;
        std::cout << m_file << std::endl;
#endif
    }
    
    std::string Path::getFullPath() const
    {
        return joinPath(m_folders) + m_sep + m_file;
    }
    
    std::string Path::getFilename() const
    {
        return m_file;
    }
    
    std::string Path::getFoldername() const
    {
        return joinPath(m_folders);
    }
    
    Path Path::getFolder() const
    {
        return Path(getFoldername());
    }
    
    std::string Path::getBasename() const
    {
        size_t index = m_file.find('.');
        return m_file.substr(0, index);
    }
    
    std::string Path::getExtname() const
    {
        size_t index = m_file.find('.');
        if (index == m_file.size())
            return m_file;
        else
            return m_file.substr(index, m_file.size() - index);
    }
    
    std::vector<std::string> Path::listDir() const
    {
        std::vector<std::string> result;
        return result;
    }
    
    std::vector<Path> Path::listDir2() const
    {
        std::vector<Path> result;
        return result;
    }
    
    bool Path::isFile() const
    {
        struct stat file_stat;
        std::string fullname = getFullPath();
        stat(fullname.c_str(), &file_stat);
        
        return (file_stat.st_mode & S_IFREG);
    }
    
    bool Path::isDirectory() const
    {
        struct stat file_stat;
        std::string fullname = getFullPath();
        stat(fullname.c_str(), &file_stat);
        
        return (file_stat.st_mode & S_IFDIR);
    }
    
    void Path::splitPath(const std::string &pathname, std::vector<std::string>& parts, std::string& last_part)
    {
        parts.clear();
        size_t index = 0;
        std::string part;
        for (size_t k = 0; k < pathname.size(); ++k)
        {
            char c = pathname[k];
            if ((c == '/') || (c =='\\'))
            {
                if (k > index)
                {
                    part = pathname.substr(index + 1, k - index - 1);
                    parts.push_back(part);
                    index = k;
                }
                else
                    index = k;
            }
        }
        if (index < pathname.size() - 1)
            last_part = pathname.substr(index + 1, pathname.size() - index - 1);
        else
            last_part.clear();
    }
    
    std::string Path::joinPath(const std::vector<std::string>& parts) const
    {
#if defined(__APPLE__)
        std::string path = StringOps::join(parts, m_sep);
        char buf[8];
        sprintf(buf, "%c", m_sep);
        return buf + path;
#else
        return StringOps::join(parts, m_sep);
#endif
    }
}
