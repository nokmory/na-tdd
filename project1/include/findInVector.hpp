#pragma once

#include <vector>

namespace utils
{
    
template <typename T>
int findInVector(std::vector<T> const &vec, T item)
{
    int pos = static_cast<int>(NULL);
    
    for (size_t i = 0; i < vec.size(); ++i)
    {
        if (item == vec[i])
            pos = static_cast<int>(i);
    }
    
    return pos;
}
    
} // namespace utils

