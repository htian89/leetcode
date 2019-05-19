/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 */
class Solution {
public:
    int reverse(int x) {
        int ret = 0;
        while(x != 0) {
            int num = x%10;
            if ((x > 0 && (ret > INT32_MAX/10 || (ret == INT32_MAX/10 && num > 7)))
                || (x < 0 && (ret < INT32_MIN/10 || (ret == INT32_MIN/10 && num < -8)))) return 0;
            ret = ret * 10 + num;
            x = x/10;
        }
        return ret;
    }
};

