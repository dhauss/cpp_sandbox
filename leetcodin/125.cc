#include <iostream>
#include <cstdint>
#include <string>
/*
125. Valid Palindrome

A phrase is a palindrome if, after converting all uppercase letters into
lowercase letters and removing all non-alphanumeric characters, it reads
the same forward and backward. Alphanumeric characters include letters
and numbers.
*/

bool is_palindrome_final(const std::string& s);
bool is_palindrome(std::string& s);
uint32_t strip_and_lower(std::string& s);

int main()
{
    auto test_1 = std::string{"A man, a plan, a canal: Panama"};
    auto test_2 = std::string{"race a car"};
    auto test_3 = std::string{" "};

    std::cout << std::boolalpha << is_palindrome_final(test_1) << '\n';
    std::cout << std::boolalpha << is_palindrome_final(test_2) << '\n';
    std::cout << std::boolalpha << is_palindrome_final(test_3) << '\n';

    std::cout << std::boolalpha << is_palindrome(test_1) << '\n';
    std::cout << std::boolalpha << is_palindrome(test_2) << '\n';
    std::cout << std::boolalpha << is_palindrome(test_3) << '\n';

    return 0;
}

bool is_palindrome_final(const std::string& s)
    // checks if a string is a palindrome in place without altering original string
{
    std::int32_t l = 0;
    std::int32_t r = s.size() - 1;

    while(l < r)
    {
        while(!isalnum(s[l]))
        {
            ++l;
        }

        while(!isalnum(s[r]))
        {
            --r;
        }

        if(tolower(s[l]) != tolower(s[r]))
        {
            return false;
        }

        ++l;
        --r;
    }

    return true;
}

bool is_palindrome(std::string& s) 
{
    // checks if string is a palindrome but alters original string
    std::int32_t l = 0;
    std::int32_t r = strip_and_lower(s) - 1;

    while(l < r)
    {
        if(s[l] != s[r]){
            return false;
        }
        ++l;
        --r;
    }

    return true;
}

std::uint32_t strip_and_lower(std::string& s)
{
    /*
    strips non-alphanumeric characters from s and converts to lowercase
    alters original string in place by placing lowercase, alphanumeric chars
    at beginning of original string

    returns: index immediately after the end of clean string, similar to str.size()
    */
    std::uint32_t end = 0;

    for(char& c: s)
    {
        if(isalnum(c)){
            s[end] = tolower(c);
            ++end;
        }
    }
    
    return end;
}