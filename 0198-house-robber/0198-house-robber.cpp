class Solution {
private:
    int solve(vector<int>& nums,vector<int>& dp,int n,int i){
        if(i < 0)return 0;
        if(i == 0)return nums[0];
        if(dp[i] != -1)return dp[i];
        int inclu=nums[i]+solve(nums,dp,n,i-2);
        int exclu=0+solve(nums,dp,n,i-1);

        return dp[i]=max(inclu,exclu);
    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        dp[0]=nums[0];
        for(int i=1;i<n;i++){
            int inclu=nums[i];
            if(i-2 >= 0){
                inclu += dp[i-2];
            }
            int exclu=dp[i-1];

            dp[i]=max(inclu,exclu);
        }
        
        return dp[n-1];
    }
};