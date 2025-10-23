class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){

            int one_ele=nums[i];
            int second_ele=target-one_ele;

            if(mp.find(second_ele) != mp.end()){
                ans.push_back(i);
                ans.push_back(mp[second_ele]);
                break;
            }

            mp[one_ele]=i;
        }
        return ans;
    }
};