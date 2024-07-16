#include <iostream>
#include <stdint.h>
#include <unordered_set>
#include <vector>
/*
217. Contains Duplicate

Given an integer array nums, return true if any value appears at least twice
in the array, and return false if every element is distinct.
*/

bool containsDuplicate(std::vector<int32_t>& nums);

int main(){
    auto test_1 = std::vector<int32_t>{1, 2, 3, 1};
    auto test_2 = std::vector<int32_t>{1, 2, 3, 4};
    auto test_3 = std::vector<int32_t>{1, 1, 1, 3, 3, 4, 3, 2, 4, 2};

    std::cout << std::boolalpha << containsDuplicate(test_1) << '\n';
    std::cout << std::boolalpha << containsDuplicate(test_2) << '\n';
    std::cout << std::boolalpha << containsDuplicate(test_3) << '\n';

    return 0;
}

bool containsDuplicate(std::vector<int32_t>& nums) {
    auto num_set = std::unordered_set<int32_t>{};
    for(auto& num: nums)
    {
        if(num_set.count(num))
        {
            return true;
        }
        num_set.insert(num);
    }
    return false;
}