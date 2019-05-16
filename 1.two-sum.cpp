/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        if (nums.size() < 2) return {};
        multimap<int,int> n_map;
        for (int i = 0; i < nums.size(); ++i)
        {
            n_map.insert(std::pair<int, int>(nums[i], i));
        }
        auto l = n_map.begin(), r = --(n_map.end());
        while (l != r) {
            int sum = l->first + r->first;
            if (sum > target) {
                --r;
                continue;
            }
            if (sum < target) {
                ++l;
                continue;
            }
            return {l->second, r->second};
        }
        return {};
    }
};

