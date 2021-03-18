#pragma once

#include <vector>

namespace utils
{
    
template <typename T>
void stableSort(std::vector<T> &vec)
{
    for (size_t start = 0; start < vec.size(); ++start)
    {
        size_t minValuePos = start;

        for (size_t i = start + 1; i < vec.size(); ++i)
        {
            if (vec[minValuePos] >= vec[i])
            {
                minValuePos = i;
            }
        }

        if (start != minValuePos) std::swap(vec[start], vec[minValuePos]);
    }
}
    
} // namespace utils
