class Solution {
public:
    void solve(vector<int>& nums,vector<int> temp,vector<vector<int>>& ans,int ind){

         if(ind == nums.size()){
            ans.push_back(temp);
            return;
         }
         for(int i=ind;i<nums.size();i++){
            temp.push_back(nums[i]);
            swap(nums[i],nums[ind]);
            solve(nums,temp,ans,ind+1);
            swap(nums[i],nums[ind]);
            temp.pop_back();
         }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(nums,temp,ans,0);
        return ans;
    }
};