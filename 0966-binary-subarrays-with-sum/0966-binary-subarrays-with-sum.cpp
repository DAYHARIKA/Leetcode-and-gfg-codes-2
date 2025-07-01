class Solution {
public:
    int count(vector<int>& nums, int goal){
        if(goal < 0)return 0;
        int n=nums.size();
        int cnt=0;
        long sum=0;
        int l=0;
        int r=0;
        while(r < n){
            sum += nums[r];
            while(sum > goal){
                sum =sum-nums[l];
                l++;
            }
            cnt += (r-l+1);
            r++;
        }
        return cnt;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        
        int cntk=count(nums,goal);
        int cntk1=count(nums,goal-1);
        return cntk-cntk1;
    }
};