#include "quadraticEquation.hpp"

#include <cmath>

namespace utils
{    

std::pair<unsigned, std::pair<float, float>> calculateDeltaZeroCase(float a, float b)
{
    return {1, {-b / (2 * a), 0}};
}

std::pair<unsigned, std::pair<float, float>> calculateDeltaPositiveCase(float a, float b, float delta)
{
    float x1 = (-b - std::sqrt(delta)) / (2 * a);
    float x2 = (-b + std::sqrt(delta)) / (2 * a);

    return{2, {x1, x2}};
}

std::pair<unsigned, std::pair<float, float>> quadraticEquation(float a, float b, float c)
{
    float x1 = 0;
    float x2 = 0;
    float n = 0;

    float delta = b * b  - 4 * a * c;

    if (delta == 0)
    {
        // n = 1;
        // x1 = -b / (2 * a);
        return calculateDeltaZeroCase(a, b);
    }
    else if (delta > 0)
    {
        // n = 2;

        // x1 = (-b - std::sqrt(delta)) / (2 * a);
        // x2 = (-b + std::sqrt(delta)) / (2 * a);
        return calculateDeltaPositiveCase(a, b, delta);
    }

    return std::pair<unsigned, std::pair<float, float>>(n, std::pair<float, float>(x1, x2));
}
    
} // namespace utils

