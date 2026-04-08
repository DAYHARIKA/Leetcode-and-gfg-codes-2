class Solution {
public:
    vector<int> solve(vector<int>& nums,int n){
        
        //can be used to find lis..
        vector<int> dp(n,1);
        vector<int> hash(n,0);
        for(int i=0;i<n;i++)hash[i]=i;


        int maxi=0;
        int endind=0;

        for(int i=0;i<n;i++){
            for(int j=i-1;j>=0;j--){

                if((nums[j]%nums[i] == 0 || nums[i]%nums[j] == 0) && dp[i] < 1+dp[j]){
                    dp[i]=1+dp[j];
                    hash[i]=j;
                }

            }
            if(dp[i] > maxi){
                maxi=dp[i];
                endind=i;
            }
        }


        vector<int> temp;
        temp.push_back(nums[endind]);

        int var=endind;
        
        while(var != hash[var]){
            
            var=hash[var];
            temp.push_back(nums[var]);
        }

        reverse(temp.begin(),temp.end());

        return temp;
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
        int n=nums.size();
        sort(nums.begin(),nums.end());
        return solve(nums,n);
    }
};