#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <string>
#include <stdexcept>
#include "include/bubble_sort.h"
#include "include/selection_sort.h"
#include "include/insertion_sort.h"

enum SORT_TYPE
{
    BUBBLE_SORT,
    SELECTION_SORT,
    INSERTION_SORT
};

void my_func(SORT_TYPE sort_type, std::vector<int> &data)
{
    auto start = std::chrono::steady_clock::now();

    switch (sort_type)
    {
    case (BUBBLE_SORT):
        bubble_sort(data.begin(), data.end());
        break;
        case (SELECTION_SORT):
        selection_sort(data.begin(), data.end());
        break;
        case (INSERTION_SORT):
        insertion_sort(data.begin(), data.end());
        break;
    }
    auto end = std::chrono::steady_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << duration.count() << "ms" << std::endl;
}

SORT_TYPE get_sort_type(std::string &sort_type)
{
    if (sort_type == "BUBBLE_SORT" || sort_type == "bubble_sort")
        return BUBBLE_SORT;
    else if (sort_type == "SELECTION_SORT" || sort_type == "selection_sort")
        return SELECTION_SORT;
    else if (sort_type == "INSERTION_SORT" || sort_type == "insertion_sort")
    return INSERTION_SORT;
    throw std::invalid_argument("Invalid sort type");
}
int main()
{
    std::string sort_type;
    std::cin >> sort_type;

    std::vector<int> data(200);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0, 100000);
    for (auto &x : data)
    {
        x = dist(gen);
        std::cout << x << " ";
    }
    std::cout << std::endl;

    my_func(get_sort_type(sort_type), data);
    for (int i : data)
    {

        std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}