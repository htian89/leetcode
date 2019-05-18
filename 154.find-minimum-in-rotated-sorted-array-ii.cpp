/*
 * @lc app=leetcode id=154 lang=cpp
 *
 * [154] Find Minimum in Rotated Sorted Array II
 */
class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.empty()) return 0;
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            // Like [1,0,1,1,1,1] or [1,1,1,1,0,1]
            if (nums[mid] == nums[r] && nums[l] == nums[mid]) {
                ++l;
                --r; 
            } else if (nums[mid] > nums[r]) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return nums[l];
    }
};

