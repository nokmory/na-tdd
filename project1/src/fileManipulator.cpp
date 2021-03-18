#include "fileManipulator.hpp"

#include <string>
#include <fstream>
#include <algorithm>

namespace utils
{    
    
bool FileManipulator::loadFile(std::string fileName)
{
    std::ifstream fileStream;
    fileStream.open(fileName);
    
    if (!fileStream.is_open()) return false;

    std::string word;

    while (fileStream >> word)
    {
        fileContents.push_back(word);
    }

    fileStream.close();
    return true;
}

bool FileManipulator::saveFile(std::string fileName) const
{
    std::ofstream fileStream;
    fileStream.open(fileName);
    
    if (!fileStream.is_open()) return false;

    for (auto word : fileContents)
    {
        fileStream << word;
    }

    fileStream.close();
    return true;
}

void FileManipulator::reverseWordOrder()
{
    std::reverse(fileContents.begin(), fileContents.end());
}

std::string FileManipulator::getWord(size_t index) const
{
    return fileContents.at(index);
}

size_t FileManipulator::count() const
{
    return fileContents.size();
}
    
} // namespace utils