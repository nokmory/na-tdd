#pragma once

#include <iosfwd>
#include <vector>

namespace utils
{
    
class FileManipulator
{
    std::vector<std::string> fileContents;
public:
    bool loadFile(std::string fileName);
    bool saveFile(std::string fileName) const;
    void reverseWordOrder();
    std::string getWord(size_t index) const;
    size_t count() const;
};
    
} // namespace utils

