/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */
class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> ret;
    sort(nums.begin(),nums.end());
    ret.reserve(nums.size());
    for (int i = 0; i + 2 < nums.size(); ++i) {
      int target = -nums[i];
      int l = i + 1, r = nums.size() - 1;
      while (l < r) {
          if (nums[l] + nums[r] < target) {
              ++l;
          } else if (nums[l] + nums[r] > target) {
              --r;
          } else {
              vector<int> triple = {nums[i], nums[l], nums[r]};
              ret.emplace_back(move(triple));
              ++l; --r;
              while (l < r && nums[l] == nums[l - 1]) ++l;
              while (l < r && nums[r] == nums[r + 1]) --r;
          }
      }
      while (i + 3 < nums.size() && nums[i + 1] == nums[i]) ++i;
    }
    return move(ret);
  }
};

