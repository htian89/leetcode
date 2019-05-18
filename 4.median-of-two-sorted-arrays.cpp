/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */
#define MAX(a,b) ((a > b) ? a : b)
#define MIN(a,b) ((a < b) ? a : b)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>* a = &nums1, * b = &nums2;    
        if (nums1.size() > nums2.size()) {
            a = &nums2;
            b = &nums1;
        }
        size_t half = (a->size() + b->size() + 1)/2;
        size_t min_i = 0, max_i = a->size();
        while(min_i <= max_i) {
            size_t i = (min_i + max_i) / 2;
            size_t j = half - i;
            if (i > min_i && (*a)[i-1] > (*b)[j]) {
                max_i = i - 1;
            } else if (i < max_i && (*a)[i] < (*b)[j-1]) {
                min_i = i + 1;
            } else {
                int left_max = 0;
                if (i == 0) {
                    left_max = (*b)[j-1];
                } else if (j == 0) {
                    left_max = (*a)[i-1];
                } else {
                    left_max = MAX((*a)[i-1],(*b)[j-1]);
                }
                if ((a->size() + b->size()) % 2 == 1) {
                    return double(left_max);
                }
                int right_min = 0;
                if (i == a->size()) {
                    right_min = (*b)[j];
                } else if (j == b->size()) {
                    right_min = (*a)[i];
                } else {
                    right_min = MIN((*a)[i],(*b)[j]);
                }
                return (left_max + right_min) / 2.0;
            }
        }
        return 0.0;
    }
};

