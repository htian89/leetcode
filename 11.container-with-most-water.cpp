/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */
class Solution {
public:
    int maxArea(vector<int>& height) {
        int most_water = 0;
        int l = 0, r = height.size() - 1;
        while (l < r) {
            int h = min(height[l], height[r]);
            most_water = max(most_water, h * (r - l));
            while (height[l] <= h && l < r) ++l;
            while (height[r] <= h && l < r) --r;
        }        
        return most_water;
    }
};

