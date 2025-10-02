#pragma once
#include <set>
#include <vector>
#include <iterator>

template <typename RandomIT>
void red_black_sort(RandomIT begin, RandomIT end)
{
    std::set<typename std::iterator_traits<RandomIT>::value_type> sort_set;
    sort_vec.reserve(std::distance(begin, end));

    for (auto i = begin; i != end; ++i)
    {
        sort_set.insert(*i);
    }

    auto it = begin;
    for (const auto &value : sort_set)
    {
        *it = value;
        ++it;
    }
}