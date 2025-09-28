class Solution {
private:
    int solve(vector<int>& coins, int amount, vector<int>& dp){

        if(amount == 0)return 0;
        if(amount < 0)return INT_MAX;
        if(dp[amount] != -1)return dp[amount];
        int mini=INT_MAX;
        for(int i=0;i<coins.size();i++){
            int temp=solve(coins,amount-coins[i],dp);
            if(temp != INT_MAX)
            mini=min(mini,1+temp);
        }
        return dp[amount]=mini;
    }
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