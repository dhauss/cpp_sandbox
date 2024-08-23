#include <cassert>
#include <cstdint>
#include <vector>

/*
11. Container With Most Water

You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.
*/

std::int32_t max_area(std::vector<std::int32_t>& height);
std::int32_t main()
{
    auto test_1 = std::vector<std::int32_t>{1,8,6,2,5,4,8,3,7};
    auto test_2 = std::vector<std::int32_t>{1,1};

    auto res_1 = max_area(test_1);
    auto res_2 = max_area(test_2);

    assert(res_1 == 49);
    assert(res_2 == 1);
}

std::int32_t max_area(std::vector<std::int32_t>& height)
{
    auto max_area = std::int32_t{0};
    auto l = std::int32_t{0};
    auto r = height.size() - 1;

    while(l < r)
    {
        auto cur_area = std::int32_t{};

        if(height[l] < height[r])
        {
            cur_area = (r - l) * height[l];
            ++l;
        }
        else
        {
            cur_area = (r - l) * height[r];
            --r;
        }
        max_area = (cur_area > max_area)? cur_area : max_area;
    }

    return max_area;
}