/*
 * @lc app=leetcode id=154 lang=cpp
 *
 * [154] Find Minimum in Rotated Sorted Array II
 */
class Solution {
    int _findMin(vector<int>& nums, int l, int r) const {
        while (l < r) {
            int mid = l + (r - l) / 2;
            // Like [1,0,1,1,1,1] or [1,1,1,1,0,1]
            if (nums[mid] == nums[r] && nums[l] == nums[mid]) {
                return min(_findMin(nums, l, mid), _findMin(nums, mid + 1, r));
            } else if (nums[mid] > nums[r]) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return nums[l];
    }
public:
    int findMin(vector<int>& nums) {
        if (nums.empty()) return 0;
        return _findMin(nums, 0, nums.size() - 1);
    }
};

