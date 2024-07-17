#include <cstdint>
#include <unordered_map>
#include <vector>

std::vector<std::int32_t> twoSum(std::vector<std::int32_t>& nums, std::int32_t target);

int main()
{
    return 0;
}

std::vector<std::int32_t> twoSum(std::vector<std::int32_t>& nums, std::int32_t target)
{
    auto num_map = std::unordered_map<std::int32_t, std::int32_t>{};
    for(std::int32_t i = 0; i < nums.size(); i++)
    {
        auto num = nums[i];
        if(num_map.count(target - num))
        {
            return std::vector<std::int32_t>{num_map[target - num], i};
        }
        num_map[num] = i;
    }
    return std::vector<std::int32_t>{};
}