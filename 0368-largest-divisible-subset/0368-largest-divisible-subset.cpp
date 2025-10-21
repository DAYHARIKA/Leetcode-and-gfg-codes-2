class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
       int n=nums.size();
        vector<int> temp;
        if(n == 0)return temp;

        sort(nums.begin(),nums.end());

        vector<int> dp(n,1);
        vector<int> hash(n,0);
        
        int maxi=1;
        int lastind=0;
        
        for(int i=1;i<n;i++){
            hash[i]=i;
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j] == 0 && dp[i] < dp[j]+1){
                    dp[i]=dp[j]+1;
                    hash[i]=j;
                }
            }
            if(maxi < dp[i]){
                maxi=dp[i];
                lastind=i;
            }
        }
        
        vector<int> ans(maxi,0);
        
        ans[maxi-1]=nums[lastind];
        
        int k=maxi-2;
        
        while(hash[lastind] != lastind){
            ans[k]=nums[hash[lastind]];
            lastind=hash[lastind];
            k=k-1;
        }

        return ans; 
    }
};