class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        
        unordered_map<int,int> prev;
        prev[0]=1;

        for(int i=1;i<=nums.size();i++){
            unordered_map<int,int> curr;
            int x=nums[i-1];
            
            for(auto &[sum,ways]:prev){

                curr[sum+x] += ways;
                curr[sum-x] += ways;
            }

            prev=curr;

        }

        return prev[target];
    } 
};