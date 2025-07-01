class Solution {
public:
    int sum_lessequalto_goal(vector<int>& nums, int goal){
        if(goal < 0){
            return 0;
        }
        int l=0,r=0,sum=0,count=0;
        while(r<nums.size()){
            sum=sum+nums[r]%2;
            while(sum>goal){
                sum=sum-nums[l]%2;
                l++;
            }
            count=count+(r-l+1);
            r++;
        }
        return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        int count1=sum_lessequalto_goal(nums,k);
        int count2=sum_lessequalto_goal(nums,k-1);
        return count1-count2;

    }
};