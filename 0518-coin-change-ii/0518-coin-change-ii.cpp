class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<unsigned long long> dp(amount+1, 0);

        // Base case: using only coins[0]
        for (int t = 0; t <= amount; t++) {
           if(t % coins[0] == 0)dp[t]=1;
        }

        for (int i = 1; i < n; i++) {
            for (int t = 0; t <= amount; t++) {
                unsigned long long nottake = dp[t];
                unsigned long long take = 0;
                if (coins[i] <= t) take = dp[t - coins[i]];
                dp[t] = take + nottake;
            }
        }
        return dp[amount];
    }

};
