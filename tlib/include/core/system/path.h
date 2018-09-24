#ifndef tlib_path_h
#define tlib_path_h

#include <string>
#include <vector>

namespace tlib
{
    enum ListDirType
    {
        LIST_FILES = 0x01,  // 0000 0001
        LIST_DIRS = 0x02,   // 0000 0010
        LIST_DOTS = 0x04,   // 0000 0100
        LIST_ALL = 0x07,    // 0000 0111
    };
    
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
        
        std::vector<std::string> listDir(int list_type) const;
        std::vector<Path> listDir2(int list_type) const;
        bool isFile() const;
        bool isDirectory() const;
        
        // get full path if . or .. or ~ exists in the path name
        Path expandDir() const;
    private:
        void splitPath(const std::string& pathname, std::vector<std::string>& parts, std::string& last_part);
        std::string joinPath(const std::vector<std::string>& parts) const;
    };
}

#endif /* tlib_path_h */
