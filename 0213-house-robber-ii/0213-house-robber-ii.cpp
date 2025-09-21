class Solution {
private:
    int solve(vector<int>& nums){
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
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        //edgecases
        if(n == 1)return nums[0];
        vector<int> first;
        vector<int> second;
        for(int i=0;i<n;i++){
            if(i != 0){
                second.push_back(nums[i]);
            }

            if(i != n-1){
                first.push_back(nums[i]);
            }
        }

        return max(solve(first),solve(second));
    }
};