class Solution {
private:
    bool solve(vector<int>& nums,int ind,int sum){
         if(sum == 0)return true;
         if(ind == 0)return nums[ind]==sum;

         int nottake=solve(nums,ind-1,sum);
         int take=false;
         if(nums[ind] <= sum){
            take=solve(nums,ind-1,sum-nums[ind]);
         }
         return take||nottake;
    }
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum += nums[i];
        }
        if(sum%2 == 1)return false;
        
        vector<vector<int>> dp(n,vector<int>((sum/2)+1,false));
        for(int i=0;i<n;i++){
            dp[i][0]=true;
        }
        if(nums[0] <= sum/2) dp[0][nums[0]] = true;

        for(int i=1;i<n;i++){
            for(int j=1;j<=sum/2;j++){
                int nottake=dp[i-1][j];
                int take=false;
                if(nums[i] <= j){
                    take=dp[i-1][j-nums[i]];
                }
                dp[i][j]=take||nottake; 
            }
        }

         return dp[n-1][sum/2];
    }
};