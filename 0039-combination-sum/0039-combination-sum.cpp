class Solution {
public:
    void solve(vector<int>& candidates, int target, vector<int> temp, vector<vector<int>>& ans,int i){
         
         if(i == candidates.size()){
            if(target == 0)ans.push_back(temp);
            return;
         }
         //not pick
         solve(candidates,target,temp,ans,i+1);
         //pick
         if(target-candidates[i] >= 0){
            temp.push_back(candidates[i]);
            solve(candidates,target-candidates[i],temp,ans,i);
         }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>> ans;
        vector<int> temp;
        solve(candidates,target,temp,ans,0);
        return ans;
    }
};