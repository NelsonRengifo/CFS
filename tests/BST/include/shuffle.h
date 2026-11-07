/*
    Fisher–Yates Algorithm

    1. Start with indices [0, 1, 2, ..., n-1].
    2. Randomly select an index from the remaining unselected positions.
    3. Swap it with the last position in the remaining range.
    4. Shrink the range by one.
    5. Repeat.

    NOTE: You are modifying the container in-place.

    NOTE: Upper must be a valid index of the given container.
*/

#pragma once

#include "BST.h"
#include <random>

template <typename T>
void shuffleContainer(T &container, size_t lower, size_t upper)
{
    std::mt19937_64 engine(1);
    size_t n = container.size();
    std::uniform_int_distribution<size_t> dist(lower, upper); // how to update the upper bound per loop

    // i represents the index of the last element to swap with.
    // j represents the random index between (lower, upper) inclusive.

    for (size_t i = n - 1; i > lower; --i)
    {
        size_t j = dist(engine);
        std::swap(container[j], container[i]);
        std::uniform_int_distribution<size_t>::param_type newParam(lower, --upper);
        dist.param(newParam);
    }
}