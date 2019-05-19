/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 *
 * https://leetcode.com/problems/3sum-closest/description/
 *
 * algorithms
 * Medium (45.23%)
 * Likes:    1071
 * Dislikes: 80
 * Total Accepted:    343K
 * Total Submissions: 751.7K
 * Testcase Example:  '[-1,2,1,-4]\n1'
 *
 * Given an array nums of n integers and an integer target, find three integers
 * in nums such that the sum is closest to target. Return the sum of the three
 * integers. You may assume that each input would have exactly one solution.
 *
 * Example:
 *
 *
 * Given array nums = [-1, 2, 1, -4], and target = 1.
 *
 * The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 *
 *
 */
class Solution {
 public:
  int threeSumClosest(vector<int>& nums, int target) {
    if (nums.size() < 3) return 0;
    int closest_sum = nums[0] + nums[1] + nums[2];
    sort(nums.begin(), nums.end());
    for (int i = 0; i + 2 < nums.size(); ++i) {
      int l = i + 1, r = nums.size() - 1;
      while (l < r) {
        int sum = nums[l] + nums[r] + nums[i];
        if (sum == target) return sum;
        if (abs(sum - target) < abs(closest_sum - target)) {
          closest_sum = sum;
        }
        if (sum < target) {
          ++l;
        } else if (sum > target) {
          --r;
        }
      }
      while (i + 3 < nums.size() && nums[i + 1] == nums[i]) ++i;
    }
    return closest_sum;
  }
};

