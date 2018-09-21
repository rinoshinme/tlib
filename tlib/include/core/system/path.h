#ifndef tlib_path_h
#define tlib_path_h

#include <string>
#include <vector>

namespace tlib
{
    /* file and directory path operations */
    class Path
    {
    private:
        std::vector<std::string> m_folders;
        std::string m_file;
        char sep;
    public:
        Path(const std::string& path_name);
        bool isFile() const;
        bool isDirectory() const;
        
        std::vector<std::string> listDir() const;
        std::vector<Path> listDir2() const;
        
        std::string getFilename() const;
        std::string getFoldername() const;
        Path getFolder() const;
        
        std::string getBasename() const;
        std::string getExtname() const;
    };
}

#endif /* tlib_path_h */
