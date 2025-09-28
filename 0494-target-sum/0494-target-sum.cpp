class Solution {
private:
    int solve(vector<int>& nums, int n, int target){
        if(n == 0){
            if(nums[0] == 0 && target == 0)return 2;
            if(target == 0)return 1;
            return nums[0]==target;
        }

        int nottake=solve(nums,n-1,target);
        int take=0;
        if(nums[n] <= target){
           take = solve(nums,n-1,target-nums[n]);
        }

        return take+nottake;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int ts=0;
        for(int i=0;i<n;i++){
            ts += nums[i];
        }

        if(ts+target < 0 || (ts+target)%2)return 0;

        int tar=(ts+target)/2;
        vector<int> dp(tar+1,0);
        vector<int> curr(tar+1,0);

        if(nums[0] == 0)dp[0]=2;
        else dp[0]=1;

        if(nums[0] != 0 && nums[0] <= tar)dp[nums[0]]=1;
 
        for(int i=1;i<n;i++){
            for(int j=0;j<=tar;j++){
                int nottake=dp[j];
                int take=0;
                if(nums[i] <= j){
                take = dp[j-nums[i]];
                }

                curr[j]=take+nottake;
            }
            dp=curr;
        }

        return dp[tar];
    }
};