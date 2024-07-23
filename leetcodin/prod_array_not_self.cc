#include <cstdint>
#include <iostream>
#include <vector>

/*
238. Product of Array Except Self

Given an integer array nums, return an array answer such that answer[i] is equal to the
product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.
*/

std::vector<std::int32_t> product_except_self(std::vector<std::int32_t>& nums);

template <typename T>   // override for convenience
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vector);

int main()
{
    auto test_1 = std::vector<std::int32_t>{1, 2, 3, 4};
    auto test_2 = std::vector<std::int32_t>{-1, 1, 0, -3, 3};

    std::cout << product_except_self(test_1) << '\n';
    std::cout << product_except_self(test_2) << '\n';

    return 0;
}

std::vector<std::int32_t> product_except_self(std::vector<std::int32_t>& nums)
{
    /*
    Intuition:
    We initialize two helper arrays, prod_from_left and prod_from_right which will 
    save the products of all elements in the input's subarrays starting from the left and right
    respectively (i.e. prod_from_left[0] = nums[0], prod_from_left[1] = nums[0] * nums[1], etc.)
    These can both be filled with a single iterations through the input array. Using
    these helper arrays, we can calculate the product of each element except for itself
    by multiplying the element in the left neighboring index from prod_from_left with
    the element from the right neighboring index of prod_from_right.

    Time/Space Analysis:
    All arrays are of size n, the size of the input array. We iterate exactly three
    times through different arrays, so overall time complexity is O(n).

    We use three separate arrays all of size n, so space complexity is also O(n)
    */

    if(nums.size() < 2)
    {
        return nums;
    }

    std::vector<std::int32_t> prod_from_left(nums.size(), nums[0]);  // initialize all values to nums[0] so prod_from_left[0] is initialized correctly
    std::vector<std::int32_t> prod_from_right(nums.size(), nums[nums.size() - 1]); // similar reasoning for initializing all values to nums[nums.size() - 1]
    std::vector<std::int32_t> res(nums.size());

    for(std::size_t i = 1; i < prod_from_left.size(); i++)
    {
        prod_from_left[i] = nums[i] * prod_from_left[i - 1];
    }

    for(std::int32_t i = prod_from_right.size() - 2; i >= 0; i--)
    {
        prod_from_right[i] = nums[i] * prod_from_right[i + 1];
    }

    res[0] = prod_from_right[1];    //manually code res[0] and res[res.size() - 1] to avoid if statements while iterating
    res[res.size() -1] = prod_from_left[prod_from_left.size() - 2];
    for(std::size_t i = 1; i < res.size() - 1; i++)
    {
        res[i] = prod_from_left[i - 1] * prod_from_right[i + 1];
    }

    return res;
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