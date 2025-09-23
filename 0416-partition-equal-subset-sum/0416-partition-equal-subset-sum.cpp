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
        
        vector<bool> prev((sum/2)+1,false);  
        vector<bool> temp((sum/2)+1,false); 
        prev[0]=true;
        if(nums[0] <= sum/2) prev[nums[0]] = true; 

        for(int i=1;i<n;i++){
            //temp[0] = true; // sum=0 always possible
            for(int j=1;j<=sum/2;j++){
                int nottake=prev[j];
                int take=false;
                if(nums[i] <= j){
                    take=prev[j-nums[i]];
                }
                temp[j]=take||nottake; 
            }
            prev=temp;
        }

         return prev[sum/2];
    }
};