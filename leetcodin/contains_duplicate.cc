#include <cstdint>
#include <cassert>
#include <iostream>
#include <unordered_set>
#include <vector>
/*
217. Contains Duplicate

Given an integer array nums, return true if any value appears at least twice
in the array, and return false if every element is distinct.
*/

using std::int32_t;
using std::uint32_t;

bool contains_duplicate(const std::vector<int32_t>& nums);

int main(){
    auto test_1 = std::vector<int32_t>{1, 2, 3, 1};
    auto test_2 = std::vector<int32_t>{1, 2, 3, 4};
    auto test_3 = std::vector<int32_t>{1, 1, 1, 3, 3, 4, 3, 2, 4, 2};

    assert(contains_duplicate(test_1));
    assert(!contains_duplicate(test_2));
    assert(contains_duplicate(test_3));

    std::cout << std::boolalpha << contains_duplicate(test_1) << '\n';
    std::cout << std::boolalpha << contains_duplicate(test_2) << '\n';
    std::cout << std::boolalpha << contains_duplicate(test_3) << '\n';

    return 0;
}

bool contains_duplicate(const std::vector<int32_t>& nums) {
    /*
    Intuition: we initialize a hash set to store all numbers we
    see for the first time while iterating through the input array. We check
    each element of the array to see if it has already been stored in the
    hash set, and if it has then we have found a duplicate element and return
    true. If we iterate through the entire input array without finding a duplicate,
    we return false.

    Time/Space Analysis: We iterate at most once through the input array, so 
    O(n) time complexity. Also O(n) space complexity, as in the worst case
    there are no duplicates and we store the entire input array in the
    num_set hash map.
    */
    auto num_set = std::unordered_set<int32_t>{};
    for(const auto& num: nums)
    {
        if(num_set.count(num))
        {
            return true;
        }
        num_set.insert(num);
    }
    return false;
}