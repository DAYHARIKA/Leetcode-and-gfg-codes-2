class Solution {
public:
    int solve(vector<int>& nums, int k){
        if(k<=0){
            return 0;
        }
        int l=0,r=0,count=0;
        unordered_map<int,int> mp;
        while(r<nums.size()){
             mp[nums[r]]++;
             while(mp.size() > k){
                  mp[nums[l]]--;
                  if(mp[nums[l]] == 0){
                    mp.erase(nums[l]);
                  }
                  l++;
             }
             count=count+(r-l+1);
             r++;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        
        int count1=solve(nums,k);
        int count2=solve(nums,k-1);
        return count1-count2;
    }
};