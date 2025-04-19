class Solution {
public:
    void solve(int n,int open,int close,string s,vector<string> &ans){
        if(open == 0 && close == 0){
            ans.push_back(s);
            return;
        }
        if(open == close){
            solve(n,open-1,close,s+'(',ans);
        }else if(open == 0){
            solve(n,open,close-1,s+')',ans);
        }else if(close == 0){
            solve(n,open-1,close,s+'(',ans);
        }else{
            solve(n,open-1,close,s+'(',ans);
            solve(n,open,close-1,s+')',ans);
        }
    }
    vector<string> generateParenthesis(int n) {
         
         vector<string> ans;
         int open=n;
         int close=n;
         solve(n,open,close,"",ans);
         return ans;
    }
};