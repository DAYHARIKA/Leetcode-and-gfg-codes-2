class Solution {

public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount+1, INT_MAX);

        // Base case: using only coins[0]
        for (int t = 0; t <= amount; t++) {
           if(t % coins[0] == 0)dp[t]=t/coins[0];
        }

        for (int i = 1; i < n; i++) {
            for (int t = 0; t <= amount; t++) {
                int nottake = dp[t];
                int take = INT_MAX;
                if (coins[i] <= t && dp[t - coins[i]] != INT_MAX) take = 1+dp[t - coins[i]];
                dp[t] = min(take,nottake);
            }
        }
        if(dp[amount] == INT_MAX)return -1;
        return dp[amount];
    }
};