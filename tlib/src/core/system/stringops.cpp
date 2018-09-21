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
        
        return result;
    }
    
}
