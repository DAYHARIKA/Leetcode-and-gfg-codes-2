class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();

        vector<int> curr(2,0);
        vector<int> prev1(2,0);
        vector<int> prev2(2,0);

        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                int profit=0;

                if(buy){
                    profit=max(-prices[ind]+prev1[0],0+prev1[1]);
                }else{
                    profit=max(prices[ind]+prev2[1],0+prev1[0]);
                }

                curr[buy]=profit;
            }
            prev2=prev1;
            prev1=curr;
        }
        return prev1[1];
    }
};