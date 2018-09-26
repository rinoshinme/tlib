#include "stringops.h"
#include <iostream>

namespace tlib
{
    std::string StringOps::trim(const std::string &input)
    {
        return trimLeft(trimRight(input));
    }

    std::string StringOps::trimLeft(const std::string &input)
    {
        if (input.size() == 0)
            return input;
        
        int index = 0;
        char c = input[index];
        while (((c == ' ') || (c == '\t') || (c == '\n')) && (index < input.size()))
        {
            index += 1;
            c = input[index];
        }
        return input.substr(index, input.size() - index);
    }
    
    std::string StringOps::trimRight(const std::string &input)
    {
        if (input.size() == 0)
            return input;
        
        int index = int(input.size() - 1);
        char c = input[index];
        while (((c == ' ') || (c == '\t') || (c == '\n')) && (index >= 0))
        {
            index -= 1;
            c = input[index];
        }
        return input.substr(0, index + 1);
    }
    
    std::vector<std::string> StringOps::split(const std::string &input, const char sep)
    {
        std::vector<std::string> result;
        int index = 0;
        std::string part;
        for (size_t k = 0; k < input.size(); ++k)
        {
            if (input[k] == sep)
            {
                part = input.substr(index, k - index);
                result.push_back(part);
                index = int(k + 1);
            }
        }
        part = input.substr(index, input.size() - index);
        result.push_back(part);
        return result;
    }
    
    std::string StringOps::join(const std::vector<std::string> &input, const char sep)
    {
        int len = 0;
        for (size_t k = 0; k < input.size(); ++k)
            len += input[k].size() + 1;
        len = len;
        char* buffer = new char[len];
        memset(buffer, 0, len);
        int pos = 0;
        for (size_t k = 0; k < input.size(); ++k)
        {
            pos += sprintf(buffer + pos, "%s%c", input[k].c_str(), sep);
        }
        std::string result = std::string(buffer, 0, len - 1);
        delete[] buffer;
        return result;
    }
    
    bool StringOps::startsWith(const std::string &input, const std::string &head)
    {
        if (head.size() > input.size())
            return false;
        for (size_t k = 0; k < head.size(); ++k)
        {
            if (input[k] != head[k])
                return false;
        }
        return true;
    }
    
    bool StringOps::endsWith(const std::string &input, const std::string &tail)
    {
        if (tail.size() > input.size())
            return false;
        for (int k = int(tail.size() - 1); k >= 0; --k)
        {
            if (input[input.size() - 1 - k] != tail[tail.size() - 1 - k])
                return false;
        }
        return true;
    }
    
    bool StringOps::checkInt(const std::string &input)
    {
        for (size_t i = 0; i < input.size(); ++i)
        {
        }
        
        return true;
    }
    
    bool StringOps::checkValid(const std::string &input, tlib::ValueType type)
    {
        if (type == ValueType::ValueInteger)
        {
            // all digits
        }
        else
        {
            // floating point, digits and one dot
        }
        return true;
    }
}
