class Solution {
public:
    bool ispalindrome(string s1){
         if(s1.length() == 1)return true;
         int l=0;
         int h=s1.length()-1;
         while(l<h){
            if(s1[l] != s1[h]){
                return false;
            }
            l++;
            h--;
         }
         return true;
    }
    void solve(string &arr,vector<vector<string>>& ans,vector<string> temp,int ind){
         if(ind == arr.length()){
            ans.push_back(temp);
            return;
         }
         for(int i=ind;i<arr.length();i++){
            string sub=arr.substr(ind,i-ind+1);
            if(ispalindrome(sub)){
                temp.push_back(sub);
                solve(arr,ans,temp,i+1);
                temp.pop_back();
            }
         }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        solve(s,ans,temp,0);
        return ans;
    }
};