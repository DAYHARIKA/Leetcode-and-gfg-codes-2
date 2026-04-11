class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        int maxi=0;
        vector<int> dp(n,1);
        vector<int> cnt(n,1);

        for(int i=0;i<n;i++){
            for(int j=i-1;j>=0;j--){

                if(nums[j]<nums[i]){

                    if(dp[i] < dp[j]+1){
                       cnt[i]=cnt[j];
                    }else if(dp[i] == dp[j]+1){
                        cnt[i] += cnt[j];
                    }

                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
            maxi=max(maxi,dp[i]);
        }

        int ans=0;

        for(int i=0;i<n;i++){
            if(dp[i] == maxi){
                ans += cnt[i];
            }
        }

        return ans;
    }
};