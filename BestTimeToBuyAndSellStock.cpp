/*
 * Say you have an array for which the ith element is the price of a given stock on day i.
 *
 * If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
 */

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int ans = 0;
        if (prices.empty()) {
            return ans;
        }
        int min_price = prices[0];
        for (size_t i = 1; i < prices.size(); i++) {
            min_price = min(min_price, prices[i]);
            ans = max(ans, prices[i]-min_price);
        }
        return ans;
    }
};
