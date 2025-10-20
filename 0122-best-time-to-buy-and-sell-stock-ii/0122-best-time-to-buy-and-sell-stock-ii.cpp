class Solution {
private:
    int solve(vector<int>& prices,int n,int ind,int buy){

        if(ind == n)return 0;

        int profit=0;
        if(buy){
           profit=max(-prices[ind]+solve(prices,n,ind+1,0),0+solve(prices,n,ind+1,1));
        }else{
            profit=max(prices[ind]+solve(prices,n,ind+1,1),0+solve(prices,n,ind+1,0));
        }

        return profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        
        int n=prices.size();

        vector<vector<int>> dp(n+1,vector<int>(2,0));

        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                int profit=0;

                if(buy){
                    profit=max(-prices[ind]+dp[ind+1][0],0+dp[ind+1][1]);
                }else{
                    profit=max(prices[ind]+dp[ind+1][1],0+dp[ind+1][0]);
                }

                dp[ind][buy]=profit;
            }
        }
        return dp[0][1];
    }
};