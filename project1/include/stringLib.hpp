#pragma once

#include <iosfwd>

namespace utils
{

class StringLib
{
    StringLib() = delete;
    StringLib(const StringLib&) = delete;
    StringLib& operator=(const StringLib&) = delete;
    StringLib& operator=(StringLib&&) = delete;
    ~StringLib() = delete;

public:
    static std::string spacesToUnderscoresRemoveNumbers(std::string input);
    static const char* errorString(unsigned errorCode);
    static bool sameStrings(std::string str1, std::string str2);
};
    
} // namespace utils

