#include <cstdint>
#include <iostream>
#include <unordered_map>
#include <vector>

/*
347. Top K Frequent Elements

Given an integer array nums and an integer k, return the k most frequent elements.
You may return the answer in any order
*/

std::vector<int> top_k_frequent(const std::vector<std::int32_t>& nums, std::int32_t k);

template <typename T>  // overload for convenience
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vector);

int main() {
    auto test_vec1 = std::vector<std::int32_t>{1, 1, 1, 2, 2, 3};
    auto test_k1 =std::int32_t{2};
    auto test_vec2 = std::vector<std::int32_t>{1};
    auto test_k2 =std::int32_t{1};

    std::cout << top_k_frequent(test_vec1, test_k1) << '\n';
    std::cout << top_k_frequent(test_vec2, test_k2) << '\n';

    return 0;
}

std::vector<int> top_k_frequent(const std::vector<std::int32_t>& nums, std::int32_t k) {
    auto count_map = std::unordered_map<std::int32_t, std::int32_t>{};
    auto count_vec = std::vector<std::vector<std::int32_t>>{nums.size()};
    auto end = count_vec.size() - 1;
    auto res_vec = std::vector<std::int32_t>{};
    for(const auto& num: nums)
    {
        if(count_map.count(num))
        {
            ++count_map[num];
        }
        else
        {
            count_map[num] = 1;
        }
    }

    for(const auto& pair: count_map)
    {
        count_vec[pair.second - 1].push_back(pair.first); // index - 1 to account for 0-indexing
    }

    while(k)
    {
        while(count_vec[end].size() && k){
            auto cur_el = count_vec[end].back();
            count_vec[end].pop_back();
            res_vec.push_back(cur_el);
            --k;
        }
        --end;
    }
    return res_vec;
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