class Solution {
public:
    int findMaxProfit(vector<int>& prices, vector<vector<int>>& dp, int i, bool canBuy) {
        if (i >= prices.size())
            return 0;

        if (dp[i][canBuy] != -1)
            return dp[i][canBuy];

        // Choice 1
        int cooldown = findMaxProfit(prices,dp, i + 1, canBuy);

        // Choice 2
        if (canBuy) {
            int buy = findMaxProfit(prices,dp, i + 1, !canBuy) - prices[i];
            dp[i][canBuy] = max(buy, cooldown);
        } else {
            int sell = findMaxProfit(prices,dp, i + 2, !canBuy) + prices[i];
            dp[i][canBuy] = max(sell, cooldown);
        }

        return dp[i][canBuy];
    }

    int maxProfit(vector<int>& prices) {

        // unordered_map<pair<int , int > , int > mpp;
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));

        return findMaxProfit(prices,dp, 0, true);
    }
};