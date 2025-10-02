#pragma once

template <typename RandomIT>
void insertion_sort(RandomIT begin, RandomIT end)
{
    for (auto i = begin + 1; i != end; ++i)
    {
        auto key = *i;
        auto j = i;
        while (j != begin && *(j - 1) > key)
        {
            *j = *(j - 1);
            --j;
        }
        *j=key;
    }
}