#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

/*
49. Group Anagrams

Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase,
typically using all the original letters exactly once.
*/

std::vector<std::vector<std::string>> group_anagrams(const std::vector<std::string>& strs);

template <typename T> // overload << for convenience
std::ostream& operator<<(std::ostream& os, const std::vector<std::vector<T>>& vector);

int main(){
    auto test_1 = std::vector<std::string>{"eat","tea","tan","ate","nat","bat"};
    auto test_2 = std::vector<std::string>{""};
    auto test_3 = std::vector<std::string>{"a"};

    std::cout << group_anagrams(test_1) << '\n';
    std::cout << group_anagrams(test_2) << '\n';
    std::cout << group_anagrams(test_3) << '\n';

    return 0;
}

std::vector<std::vector<std::string>> group_anagrams(const std::vector<std::string>& strs)
{
    /*
    Intuition:
    We initialize a hash map to store the sorted version of each string
    as a key. By sorting the string, we ensure that each anagram will be stored in the same
    bucket. The value will correspond to the index of the 2D vector of strings returned
    as a result.
    
    While iterating through the input array. whenever we see a unique anagram for the first
    time, we add it to the sorted_word_map hash map, and set cur_i as the value before
    incrementing cur_i for the next unique anagram. We also initialize a vector of strings
    with the original string to add to the 2D result vector.

    If we find an anagram that has been seen before, we find its first index in the 2D
    results vector through the sorted_word_map hash map and use that index to append the
    original string to its anagram's vector within the 2D results vector.

    Time/Space Analysis:
    As we iterate through the original vector exactly once and all initialization, query,
    and append operations are constant operations, the bottleneck is in sorting each string.
    This results in O(n log n) time complexity, where n is really the number of char's
    in the input vector.

    The 2D res vector can store references to the original string, but the sorted_word_map
    necessarily holds sorted copies of the original strings. In the worst case each string
    will have a unique anagram, so that this algorithm necessarily uses O(n) space.
    */
    auto sorted_word_map = std::unordered_map<std::string, std::uint32_t>{};
    auto res = std::vector<std::vector<std::string>>{};
    auto cur_i = std::uint32_t{0};

    for(const auto& str: strs)
    {
        auto sorted_str = str;
        std::sort(sorted_str.begin(), sorted_str.end());

        if(sorted_word_map.count(sorted_str))
        {
            auto index = sorted_word_map[sorted_str];
            res[index].push_back(str);
        }
        else
        {
            res.push_back(std::vector<std::string>{str});
            sorted_word_map.insert({sorted_str, cur_i});
            ++cur_i;
        }
    }

    return res;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<std::vector<T> >& vector)
{
    // Overload << operator to print all elements of inner vectors within own brackets
    for (auto inner_vec : vector) {
        os << "[ ";
            for (auto element : inner_vec)
            {
                os << "\"" << element << "\" ";
            }
        os << ']';
    }

    return os;
}