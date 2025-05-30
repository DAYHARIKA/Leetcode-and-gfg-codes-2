class Solution {
public:
    void solve(vector<int>& candidates, int target, vector<int> temp, vector<vector<int>>& ans,int ind){
         
        if(target == 0){
            ans.push_back(temp);
            return;
        }
        for(int i=ind;i<candidates.size();i++){
            if(i>ind && candidates[i]==candidates[i-1])continue;
            if(candidates[i] > target)continue;
            temp.push_back(candidates[i]);
            solve(candidates,target-candidates[i],temp,ans,i+1);
            temp.pop_back();       
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;
        solve(candidates,target,temp,ans,0);
        vector<vector<int>> ans1(ans.begin(),ans.end());
        return ans1;
    }
};