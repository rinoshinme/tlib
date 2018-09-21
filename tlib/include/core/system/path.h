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
        char m_sep;
    public:
        Path(const std::string& path_name);
        
        std::string getFullPath() const;
        std::string getFilename() const;
        std::string getFoldername() const;
        Path getFolder() const;
        
        std::string getBasename() const;
        std::string getExtname() const;
        
        std::vector<std::string> listDir() const;
        std::vector<Path> listDir2() const;
        bool isFile() const;
        bool isDirectory() const;
    private:
        void splitPath(const std::string& pathname, std::vector<std::string>& parts, std::string& last_part);
        std::string joinPath(const std::vector<std::string>& parts) const;
    };
}

#endif /* tlib_path_h */
