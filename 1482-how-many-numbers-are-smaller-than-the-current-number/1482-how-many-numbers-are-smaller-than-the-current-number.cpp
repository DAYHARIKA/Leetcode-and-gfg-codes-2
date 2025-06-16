class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {

        vector<int> ans;
        vector<int> count(101,0);
        //count how many times each element present
        for(int i=0;i<nums.size();i++){
            count[nums[i]]++;
        } 
        // 0 1 2 3 4 5 indexes
        // 0 2 3 1 1 1
        for(int i=1;i<=100;i++){
            count[i] += count[i-1];
        }

        for(int i=0;i<nums.size();i++){
            if(nums[i] == 0)
            ans.push_back(0);
            else 
            ans.push_back(count[nums[i]-1]);
        }
        return ans;
    }
};