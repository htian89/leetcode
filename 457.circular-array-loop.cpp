/*
 * @lc app=leetcode id=457 lang=cpp
 *
 * [457] Circular Array Loop
 *
 * https://leetcode.com/problems/circular-array-loop/description/
 *
 * algorithms
 * Medium (27.48%)
 * Likes:    142
 * Dislikes: 900
 * Total Accepted:    17.8K
 * Total Submissions: 64.6K
 * Testcase Example:  '[2,-1,1,2,2]'
 *
 * You are given a circular array nums of positive and negative integers. If a
 * number k at an index is positive, then move forward k steps. Conversely, if
 * it's negative (-k), move backward k steps. Since the array is circular, you
 * may assume that the last element's next element is the first element, and
 * the first element's previous element is the last element.
 *
 * Determine if there is a loop (or a cycle) in nums. A cycle must start and
 * end at the same index and the cycle's length > 1. Furthermore, movements in
 * a cycle must all follow a single direction. In other words, a cycle must not
 * consist of both forward and backward movements.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: [2,-1,1,2,2]
 * Output: true
 * Explanation: There is a cycle, from index 0 -> 2 -> 3 -> 0. The cycle's
 * length is 3.
 *
 *
 * Example 2:
 *
 *
 * Input: [-1,2]
 * Output: false
 * Explanation: The movement from index 1 -> 1 -> 1 ... is not a cycle, because
 * the cycle's length is 1. By definition the cycle's length must be greater
 * than 1.
 *
 *
 * Example 3:
 *
 *
 * Input: [-2,1,-1,-2,-2]
 * Output: false
 * Explanation: The movement from index 1 -> 2 -> 1 -> ... is not a cycle,
 * because movement from index 1 -> 2 is a forward movement, but movement from
 * index 2 -> 1 is a backward movement. All movements in a cycle must follow a
 * single direction.
 *
 *
 *
 * Note:
 *
 *
 * -1000 ≤ nums[i] ≤ 1000
 * nums[i] ≠ 0
 * 1 ≤ nums.length ≤ 5000
 *
 *
 *
 *
 * Follow up:
 *
 * Could you solve it in O(n) time complexity and O(1) extra space complexity?
 */
class Solution {
 public:
  bool circularArrayLoop(vector<int>& nums) {
    if (nums.size() < 2) return false;
    int len = nums.size();
    // i is start index
    for (int i = 0; i < len; ++i) {
      // direction: 0 default, 1:forward, 2:backward, 3:not single direction
      int cur = i, pre = cur, dir = 0;
      while (nums[cur] <= 1000) {
        pre = cur;
        cur = (cur + nums[cur]) % len;
        // Judge direction.
        if (nums[pre] < 0) {
          // Convert index to a positive number.
          cur = (cur < 0) ? cur + len: cur;
          // backward direction.
          dir = (dir == 0 || dir == 2) ? 2 : 3;
        } else {
          // forward direction.
          dir = (dir == 0 || dir == 1) ? 1 : 3;
        }
        // The cycle must all follow a single direction.
        if (dir == 3) break;
        // Mark it's start index.
        nums[pre] = 1001 + i;
        // cycle's length equals 1.
        if (cur == pre) break;
      }
      // If it is marked, it is traversed a second time, so there is a cycle.
      if (dir != 3 && pre != cur && nums[cur] == (1001 + i)) return true;
    }
    return false;
  }
};

