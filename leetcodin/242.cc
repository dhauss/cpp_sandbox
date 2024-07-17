#include <iostream>
#include <string>
#include <unordered_map>
/*
242. Valid Anagram

Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different
word or phrase, typically using all the original letters exactly once.
*/

bool is_anagram(const std::string& s, const std::string& t);

int main()
{
    auto test_1s = std::string{"anagram"};
    auto test_1t = std::string{"nagaram"};

    auto test_2s = std::string{"rat"};
    auto test_2t = std::string{"car"};

    auto test_3s = std::string{""};
    auto test_3t = std::string{" "};

    std::cout << std::boolalpha << is_anagram(test_1s, test_1t) << '\n';
    std::cout << std::boolalpha << is_anagram(test_2s, test_2t) << '\n';
    std::cout << std::boolalpha << is_anagram(test_3s, test_3t) << '\n';

    return 0;
}

bool is_anagram(const std::string& s, const std::string& t)
{
    auto s_count = std::unordered_map<char, std::int32_t>{};

    // create hash count of string s
    for(const auto& c: s)
    {
        if(s_count.count(c))
        {
            ++s_count[c];
        }
        else
        {
            s_count.insert({c, 1});
        }
    }

    // decrement char counts in s by chars in t, return false if count < 1
    for(const auto& c: t)
    {
        if(!s_count.count(c) || s_count[c] < 1)
        {
            return false;
        }

        --s_count[c];
    }
    
    // check for 'leftovers' in s
    for(const std::pair<const char, std::int32_t>& entry: s_count)
    {
        if(entry.second != 0)
        {
            return false;
        }
    }   

    return true;
}