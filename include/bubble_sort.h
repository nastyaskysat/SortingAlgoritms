#pragma once
#include <vector>
#include <iostream>

template <typename RandomIT>
void bubble_sort(RandomIT begin, RandomIT end)
{
    for (auto j = begin; j != end - 1; ++j)
    {
        for (auto i = begin; i != end; i++)
        {
            if (*i > *(i + 1))
            {
                std::iter_swap(i, i + 1);
            }
        }
    }
}
