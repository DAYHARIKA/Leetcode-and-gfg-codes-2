class Solution {
public:
    void solve(vector<int>& nums,vector<int> temp,vector<vector<int>> &ans,int ind){
        if(ind == nums.size()){
            return;
        }
        for(int i=ind;i<nums.size();i++){
            if(i>ind && nums[i] == nums[i-1])continue;
            temp.push_back(nums[i]);
            ans.push_back(temp);
            solve(nums,temp,ans,i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> temp;
        vector<vector<int>> ans;
        ans.push_back(temp);
        solve(nums,temp,ans,0);
        return ans;
    }
};