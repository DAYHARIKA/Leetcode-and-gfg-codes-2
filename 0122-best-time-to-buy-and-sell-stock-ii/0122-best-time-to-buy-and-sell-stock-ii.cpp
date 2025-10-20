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

        vector<int> curr(2,0);
        vector<int> prev(2,0);

        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                int profit=0;

                if(buy){
                    profit=max(-prices[ind]+prev[0],0+prev[1]);
                }else{
                    profit=max(prices[ind]+prev[1],0+prev[0]);
                }

                curr[buy]=profit;
            }
            prev=curr;
        }
        return prev[1];
    }
};