#include "stringLib.hpp"

#include <string>
#include <iostream>

namespace utils
{

std::string StringLib::spacesToUnderscoresRemoveNumbers(std::string input)
{
    size_t i = 0;
    size_t o = 0;
    std::string output(input);

    while (i < input.length())
    {
        if (input[i] != ' ' && (input[i] < '0' || input[i] > '9'))
        {
            output[o++] = input[i++];
        }
        else if (input[i] >= '0' && input[i] <= '9')
        {
            i++;
        }
        else if (input[i] == ' ')
        {
            output[o++] = '_';
            i++;
        }
    }

    return output.substr(0,o);
}

const char* StringLib::errorString(unsigned errorCode)
{
    return "Error Code: " + errorCode;
}

bool StringLib::sameStrings(std::string str1, std::string str2)
{
    return !str1.compare(str2);
}
    
} // namespace utils

