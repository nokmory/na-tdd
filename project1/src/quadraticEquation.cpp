#include "quadraticEquation.hpp"

#include <cmath>

namespace utils
{
std::pair<unsigned, std::pair<float, float>> quadraticEquation(float a, float b, float c)
{
    float x1 = 0;
    float x2 = 0;
    float n = 0;

    float delta = b * b - 4 * a * c;

    if (delta == 0)
    {
        n = 1;
        x1 = -b / (2 * a);
    }
    else if (delta > 0)
    {
        n = 2;
        x1 = (-b - std::sqrt(delta)) / (2 * a);
        x2 = (-b + std::sqrt(delta)) / (2 * a);
    }

    return std::pair<unsigned, std::pair<float, float>>(n, std::pair<float, float>(x1, x2));
}

} // namespace utils
