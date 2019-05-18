/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_buy = INT_MAX;       
        int max_profit = 0;
        for (auto &&price : prices)
        {
            if (price < min_buy) {
                min_buy = price;
                continue;
            }
            if (price - min_buy > max_profit) {
                max_profit = price - min_buy;
            }
        }
        return max_profit;
        
    }
};

