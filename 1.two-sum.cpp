/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */
class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, size_t> n_map;
    for (size_t i = 0; i < nums.size(); i++) {
      auto it = n_map.find(target - nums[i]);
      if (it != n_map.end() && it->second != i) return {it->second, i};
      n_map[nums[i]] = i;
    }
    return {0, 0};
  }
};