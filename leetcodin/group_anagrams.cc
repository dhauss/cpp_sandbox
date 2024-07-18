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

template <typename T>
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
            sorted_word_map.insert({sorted_str, cur_i});
            res.push_back(std::vector<std::string>{str});
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