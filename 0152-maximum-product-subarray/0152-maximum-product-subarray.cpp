class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int n=nums.size();
        int sum1=1;
        int sum2=1;
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            sum1 *= nums[i];
            sum2 *= nums[n-1-i];

            maxi=max(maxi,max(sum1,sum2));

            if(sum1 == 0)sum1=1;
            if(sum2 == 0)sum2=1;
        }

        return maxi;
    }
};