class Solution {
private:
    int solve(vector<int>& nums,int ind,int prev,vector<vector<int>>& dp){
        if(ind == nums.size())return 0;

        if(dp[ind][prev+1] != -1)return dp[ind][prev+1];
        //nottake
        int len=0+solve(nums,ind+1,prev,dp);
        //take
        if(prev == -1 || nums[prev] < nums[ind]){
           len=max(len,1+solve(nums,ind+1,ind,dp));
        }

        return dp[ind][prev+1]=len;

    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        if(n == 0)return 0;
        vector<int> dp(n,1);
        int maxi=1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){

                if(nums[j]  < nums[i]){
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
            maxi=max(maxi,dp[i]);
        }

        return maxi;
    }
};