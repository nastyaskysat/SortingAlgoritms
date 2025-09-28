#pragma once
#include <vector>
#include <algorithm>

template <typename RandomT>
void selection_sort(RandomT begin, RandomT end)
{

    for (auto i = begin; i != end - 1; ++i)
    {
        auto min_element = i;
        for (auto j = i + 1; j != end; ++j)
        {
            if (*j < *min_element)
            {
                min_element = j;
            }
            
        }
        if (min_element!= i){
            std::iter_swap(i, min_element);
            }
       
    }
   
}