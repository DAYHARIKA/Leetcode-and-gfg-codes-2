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
        vector<int> dp(amount+1,INT_MAX);
        dp[0]=0;

        for(int i=1;i<=amount;i++){
            int mini=INT_MAX;
            for(int j=0;j<coins.size();j++){
                if(i-coins[j] >= 0 && dp[i-coins[j]] != INT_MAX){
                    int temp=dp[i-coins[j]];
                    mini=min(mini,1+temp);
                }   
            }
            dp[i]=mini;
        }
        
        if(dp[amount] == INT_MAX)return -1;
        return dp[amount];
    }
};