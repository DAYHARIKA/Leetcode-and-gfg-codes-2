class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();

        vector<int> curr(2,0);
        vector<int> prev(2,0);

        for(int ind=n-1;ind>=0;ind--){
            curr[1]=max(-prices[ind]+prev[0],0+prev[1]);
            curr[0]=max(prices[ind]+prev[1]-fee,0+prev[0]); 
            prev=curr;
        }
        return prev[1];
    }
};