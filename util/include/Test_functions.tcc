#include "Test_functions.hpp"

template <typename T>
std::vector<T> concatenate_vectors(std::vector<std::vector<T>> vectors)
{
    std::vector<T> combined;
    combined.reserve(vectors[0].size() + vectors[1].size());
    for (const auto& vector : vectors)
    {
        combined.insert(combined.end(), vector.begin(), vector.end());
    }
    return combined;
}
