class Solution {
public:
    void solve(int k, int n, vector<int> temp, vector<vector<int>>& ans, int i){
         if(temp.size() == k && n == 0){
            ans.push_back(temp);
            return;
         }
         if(i>9 || temp.size() > k){
            return;
         }
         //not pick
         solve(k,n,temp,ans,i+1);
         temp.push_back(i);
         solve(k,n-i,temp,ans,i+1);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        if(k > n)return ans;
        vector<int> temp;
        solve(k,n,temp,ans,1);
        return ans;
    }
};