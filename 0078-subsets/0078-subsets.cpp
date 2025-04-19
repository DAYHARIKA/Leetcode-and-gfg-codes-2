class Solution {
public:
    void solve(vector<int>& nums,int i,vector<int> temp,vector<vector<int>> &ans){
        if(i==nums.size()){
            ans.push_back(temp);
            return;
        }
        solve(nums,i+1,temp,ans);
        temp.push_back(nums[i]);
        solve(nums,i+1,temp,ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> ans;
        solve(nums,0,temp,ans);
        return ans;
    }
};