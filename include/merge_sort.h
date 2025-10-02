#pragma once
#include <vector>

template <typename RandomIT>
void merge_impl(RandomIT begin, RandomIT mid, RandomIT end) {
    
    std::vector<typename std::iterator_traits<RandomIT>::value_type> buffer;
    buffer.reserve(std::distance(begin, end)); // резервируем память
    
    auto left = begin;
    auto right = mid;
    
    while (left != mid && right != end) {
        if (*left <= *right) {
            buffer.push_back(*left);
            ++left;
        } else {
            buffer.push_back(*right);
            ++right;
        }
    }
    
    while (left != mid) {
        buffer.push_back(*left);
        ++left;
    }
    
    while (right != end) {
        buffer.push_back(*right);
        ++right;
    }
    
    std::copy(buffer.begin(), buffer.end(), begin);
}

template <typename RandomIT>
void merge_sort(RandomIT begin, RandomIT end)
{
    if (begin == end || std::next(begin) == end)
    {
        return;
    }
    auto mid = begin;
    std::advance(mid, (std::distance(begin, end)) / 2);
    merge_sort(begin, mid);
    merge_sort(mid, end);
    merge_impl(begin, mid, end);
}

