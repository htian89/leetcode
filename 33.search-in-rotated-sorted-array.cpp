/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 *
 * https://leetcode.com/problems/search-in-rotated-sorted-array/description/
 *
 * algorithms
 * Medium (33.37%)
 * Likes:    3286
 * Dislikes: 374
 * Total Accepted:    523.2K
 * Total Submissions: 1.6M
 * Testcase Example:  '[4,5,6,7,0,1,2]\n0'
 *
 * Suppose an array sorted in ascending order is rotated at some pivot unknown
 * to you beforehand.
 *
 * (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
 *
 * You are given a target value to search. If found in the array return its
 * index, otherwise return -1.
 *
 * You may assume no duplicate exists in the array.
 *
 * Your algorithm's runtime complexity must be in the order of O(log n).
 *
 * Example 1:
 *
 *
 * Input: nums = [4,5,6,7,0,1,2], target = 0
 * Output: 4
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [4,5,6,7,0,1,2], target = 3
 * Output: -1
 *
 */

// @lc code=start
class Solution {
 public:
  int search(vector<int>& nums, int target) {
    // successed
    for (int i = 0 ; i < 3; ++i) {
      if (i >= nums.size()) return -1;
      if (nums[i] == target) return i;
    }
    nums[0] = 3;
    nums[1] = nums.size() - 1;
    // nums[0] : l
    // nums[1] : r
    // nums[2] : mid
    while (nums[0] <= nums[1]) {
      nums[2] = nums[0] + (nums[1] - nums[0] + 1) / 2;
      if (nums[nums[2]] == target) return nums[2];
      if (nums[nums[0]] <= nums[nums[2]]) {
        // left is ascending order
        if (target >= nums[nums[0]] && target < nums[nums[2]]) {
          nums[1] = nums[2] - 1;
        } else {
          nums[0] = nums[2] + 1;
        }
      } else {
        // right is ascending order
        if (target > nums[nums[2]] && target <= nums[nums[1]]) {
          nums[0] = nums[2] + 1;
        } else {
          nums[1] = nums[2] - 1;
        }
      }
    }
    return -1;
  }
  int search_v2_sucess(vector<int>& nums, int target) {
    int l = 0, r = nums.size() - 1;
    while (l <= r) {
      int mid = l + (r - l + 1) / 2;
      if (nums[mid] == target) return mid;
      if (nums[l] <= nums[mid]) {
        // left is ascending order
        if (target >= nums[l] && target < nums[mid]) {
          r = mid - 1;
        } else {
          l = mid + 1;
        }
      } else {
        // right is ascending order
        if (target > nums[mid] && target <= nums[r]) {
          l = mid + 1;
        } else {
          r = mid - 1;
        }
      }
    }
    return -1;
  }
};
// @lc code=end

