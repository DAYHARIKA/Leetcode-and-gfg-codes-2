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
        // vector<int> dp(n,-1);
        // dp[0]=nums[0];
        int prev1=0;
        int prev2=nums[0];
        for(int i=1;i<n;i++){
            int inclu=nums[i]+prev1;
           
            int exclu=prev2;

            int curr=max(inclu,exclu);
            prev1=prev2;
            prev2=curr;
        }
        
        return prev2;
    }
};