/*
 * @lc app=leetcode id=153 lang=cpp
 *
 * [153] Find Minimum in Rotated Sorted Array
 */
class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            if (l == r) return nums[l];
            int mid = l + (r - l) / 2;
            if (min(nums[l], nums[mid]) > min(nums[mid + 1], nums[r])) {
                if (nums[mid + 1] < nums[r]) return nums[mid + 1];
                l = mid + 1;
            } else {
                if (nums[l] < nums[mid]) return nums[l];
                r = mid;
            }
        }
        return 0;
    }
};

