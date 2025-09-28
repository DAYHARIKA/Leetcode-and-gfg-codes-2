class Solution {
public:
    vector<vector<int>> dp;
    long long knapsack(int i, int a, vector<int>& coins) {
        if (a == 0)
            return 1;
        if (i < 0)
            return (a == 0) ? 1 : 0;
        if (dp[i][a] != -1)
            return dp[i][a];
        else {
            if (a >= coins[i]) {
                int o1 = knapsack(i, a - coins[i], coins);
                int o2 = knapsack(i - 1, a, coins);
                return dp[i][a] = o1 + o2;
            } else {
                return dp[i][a] = knapsack(i - 1, a, coins);
            }
        }
    }
    int change(int amount, vector<int>& coins) {
        dp.assign(305,vector<int>(5005,-1));
       return  knapsack(coins.size() - 1, amount, coins);
    }
};
