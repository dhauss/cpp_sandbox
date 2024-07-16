#include <iostream>
#include <stdint.h>
#include <string>
/*
125. Valid Palindrome

A phrase is a palindrome if, after converting all uppercase letters into
lowercase letters and removing all non-alphanumeric characters, it reads
the same forward and backward. Alphanumeric characters include letters
and numbers.
*/

bool isPalindrome(const std::string& s);
std::string strip_and_lower(const std::string& s);

int main()
{
    auto test_1 = std::string{"A man, a plan, a canal: Panama"};
    auto test_2 = std::string{"race a car"};
    auto test_3 = std::string{" "};

    std::cout << std::boolalpha << isPalindrome(test_1) << '\n';
    std::cout << std::boolalpha << isPalindrome(test_2) << '\n';
    std::cout << std::boolalpha << isPalindrome(test_3) << '\n';

    return 0;
}

bool isPalindrome(const std::string& s) 
{
    auto s_clean = strip_and_lower(s);
    int32_t l = 0;
    int32_t r = s_clean.size() - 1;

    while(l < r)
    {
        if(s_clean[l] != s_clean[r]){
            return false;
        }
        ++l;
        --r;
    }

    return true;
}

std::string strip_and_lower(const std::string& s)
{
    auto s_clean = std::string{};

    for(const char& c: s)
    {
        if(isalnum(c)){
            s_clean += tolower(c);
        }
    }
    
    return s_clean;
}