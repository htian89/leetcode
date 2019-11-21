/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 *
 * https://leetcode.com/problems/next-permutation/description/
 *
 * algorithms
 * Medium (31.36%)
 * Likes:    2387
 * Dislikes: 790
 * Total Accepted:    291.5K
 * Total Submissions: 929.3K
 * Testcase Example:  '[1,2,3]'
 *
 * Implement next permutation, which rearranges numbers into the
 * lexicographically next greater permutation of numbers.
 *
 * If such arrangement is not possible, it must rearrange it as the lowest
 * possible order (ie, sorted in ascending order).
 *
 * The replacement must be in-place and use only constant extra memory.
 *
 * Here are some examples. Inputs are in the left-hand column and its
 * corresponding outputs are in the right-hand column.
 *
 * 1,2,3 → 1,3,2
 * 3,2,1 → 1,2,3
 * 1,1,5 → 1,5,1
 *
 */

// @lc code=start
class Solution {
public:
 void Reverse(vector<int>& nums, int l, int r) const {
   int tmp = 0;
   for (; l < r; ++l, --r) {
     tmp = nums[l];
     nums[l] = nums[r];
     nums[r] = tmp;
   }
 }
 void nextPermutation(vector<int>& nums) {
   if (nums.size() < 2) return;
   int i = nums.size() - 2;
   while (i >= 0 && nums[i] >= nums[i + 1]) {
     --i;
   }
   // Reverse(nums, i + 1, nums.size() - 1);
   std::reverse(nums.begin() + i + 1, nums.end());
   if (i == -1) return;
   auto first_gt = std::upper_bound(nums.begin() + i, nums.end(), nums[i]);
   std::iter_swap(&(nums[i]), first_gt);
 }
};
// @lc code=end

