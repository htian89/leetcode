/*
 * @lc app=leetcode id=123 lang=cpp
 *
 * [123] Best Time to Buy and Sell Stock III
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int cost1 = INT_MAX, profit1 = 0, cost2 = INT_MAX, profit2 = 0;
        for (auto &&price : prices) {
            // 获取第一次购买最小的花费
            cost1 = min(cost1, price);
            // 获取第一次卖最大利润
            profit1 = max(profit1, price - cost1);
            // 获取第二次购买最小的花费
            cost2 = min(cost2, price - profit1);
            // 获取第二次卖最大利润
            profit2 = max(profit2, price - cost2);
        }
        return profit2; 
    }
};

