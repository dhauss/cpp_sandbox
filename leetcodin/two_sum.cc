#include <cstdint>
#include <iostream>
#include <ostream>
#include <unordered_map>
#include <vector>
/*
1. Two Sum

Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.
*/

std::vector<std::int32_t> two_sum(std::vector<std::int32_t>& nums, std::int32_t target);

template <typename T> // overload >> to print vectors for convenience
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vector);

int main()
{
    auto test_1 = std::vector<std::int32_t>{2,7,11,15};
    auto test_1_target = std::int32_t{9};

    auto test_2 = std::vector<std::int32_t>{3,2,4};
    auto test_2_target = std::int32_t{6};

    auto test_3 = std::vector<std::int32_t>{3, 3};
    auto test_3_target = std::int32_t{6};

    std::cout << two_sum(test_1, test_1_target) << '\n';
    std::cout << two_sum(test_2, test_2_target) << '\n';
    std::cout << two_sum(test_3, test_3_target) << '\n';

    return 0;
}

std::vector<std::int32_t> two_sum(std::vector<std::int32_t>& nums, std::int32_t target)
{
    /*
    Intuition:
    We use a hash map to store numbers we have already seen while iterating
    through the input array. The input numbers is stored as the key, and its index stored
    as the value. When we consider a new number, we use the target value to calculate what
    number is required to add to the current number in order to reach our target. We
    check the hash map of seen numbers and their indexes, and if that required number
    is contained in the hash map, we retrieve its index to return along with the current
    number's index

    Time/Space Analysis:
    We iterate through the input array at most exactly once, and given all query and
    insertion methods are constant time operations, the algorithm is O(n).

    We create a hash map that in the worst case contains all numbers from the input
    array and their indexes, giving us a space usage of O(n)
    */
    auto num_map = std::unordered_map<std::int32_t, std::int32_t>{};
    for(std::int32_t i = 0; i < nums.size(); i++)
    {
        auto num = nums[i];
        if(num_map.count(target - num))
        {
            return std::vector<std::int32_t>{num_map[target - num], i};
        }
        num_map[num] = i;
    }
    return std::vector<std::int32_t>{};
}


template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vector)
{
    // Overload << operator to print all elements of vectors
    for (auto element : vector) {
        os << element << " ";
    }

    return os;
}