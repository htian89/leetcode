/*
 * @lc app=leetcode id=18 lang=cpp
 *
 * [18] 4Sum
 *
 * https://leetcode.com/problems/4sum/description/
 *
 * algorithms
 * Medium (30.36%)
 * Likes:    1028
 * Dislikes: 207
 * Total Accepted:    231.2K
 * Total Submissions: 759.9K
 * Testcase Example:  '[1,0,-1,0,-2,2]\n0'
 *
 * Given an array nums of n integers and an integer target, are there elements
 * a, b, c, and d in nums such that a + b + c + d = target? Find all unique
 * quadruplets in the array which gives the sum of target.
 *
 * Note:
 *
 * The solution set must not contain duplicate quadruplets.
 *
 * Example:
 *
 *
 * Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.
 *
 * A solution set is:
 * [
 * ⁠ [-1,  0, 0, 1],
 * ⁠ [-2, -1, 1, 2],
 * ⁠ [-2,  0, 0, 2]
 * ]
 *
 *
 */
class Solution {
 public:
  vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> ret;
    if (nums.size() < 4) return ret;
    sort(nums.begin(), nums.end());
    ret.reserve(nums.size());
    for (int i = 0; i + 3 < nums.size(); ++i) {
      for (int j = i + 1; j + 2 < nums.size(); ++j)
      {
        int l = j + 1, r = nums.size() - 1;
        int expect_sum = target - nums[i] - nums[j];
        while (l < r) {
          int sum = nums[l] + nums[r];
          if (sum < expect_sum) {
            ++l;
          } else if (sum > expect_sum) {
            --r;
          } else {
            vector<int> quadruplet = {nums[i],nums[j],nums[l],nums[r]};
            ret.emplace_back(move(quadruplet));
            ++l;
            --r;
            while (l < r && nums[l - 1] == nums[l]) ++l;
            while (l < r && nums[r + 1] == nums[r]) --r;
          }
        }
        while (j + 3 < nums.size() && nums[j] == nums[j + 1]) ++j;
      }
      while (i + 4 < nums.size() && nums[i] == nums[i + 1]) ++i;
    }
    return move(ret);
  }
};
