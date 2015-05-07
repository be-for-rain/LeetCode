/*
 * Say you have an array for which the ith element is the price of a given stock on day i.
 *
 * Design an algorithm to find the maximum profit. You may complete at most two transactions.
 *
 * Note:
 * You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
 */
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() <= 1) {
            return 0;
        }
        vector<int> f(prices.size(), 0), g(prices.size(), 0);
        g[0] = prices[0];
        int minprice = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            minprice = min(minprice, prices[i]);
            int tmp = prices[i]-minprice;
            f[i] = max(f[i-1], tmp);    //until i, one transaction, the max profit
            g[i] = prices[i]-f[i-1];    //i as the start of the second transaction, its goodness?
        }
        int ming = g[0], ans = 0;
        for (int i = 1; i < prices.size(); i++) {
            int tmp = prices[i]-ming;
            ans = max(ans, tmp);
            ming = min(ming, g[i]);
        }
        return ans;
    }
};
