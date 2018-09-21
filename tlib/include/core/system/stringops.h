#ifndef tlib_stringops_h
#define tlib_stringops_h

#include <string>
#include <vector>

namespace tlib
{
    /* string operations */
    class StringOps
    {
    public:
        static std::string trim(const std::string& input);
        static std::string trimLeft(const std::string& input);
        static std::string trimRight(const std::string& input);
        
        static std::vector<std::string> split(const std::string& input, const char sep);
        static std::string join(const std::vector<std::string>& input, const char sep);
        
        static bool startsWith(const std::string& input, const std::string& head);
        static bool endsWith(const std::string& input, const std::string& tail);
    };
}

#endif /* tlib_stringops_h */
