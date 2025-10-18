class Solution {
private:
    int solve(string s,string t,int ind1,int ind2,vector<vector<int>>& dp){
        if(ind1 <= 0 || ind2 <= 0){
            return 0;
        }
        if(dp[ind1][ind2] != -1)return dp[ind1][ind2];
        if(s[ind1-1] == t[ind2-1]){
            return dp[ind1][ind2]=1+solve(s,t,ind1-1,ind2-1,dp);
        }
        return dp[ind1][ind2]=0+max(solve(s,t,ind1-1,ind2,dp),solve(s,t,ind1,ind2-1,dp));
    }
public:
    int longestPalindromeSubseq(string s) {
        
        string t=s;
        reverse(t.begin(),t.end());
        int n=s.length();

        vector<int> curr(n+1,0);
        vector<int> prev(n+1,0);

        for(int ind1=1;ind1 <= n;ind1++){
            for(int ind2=1;ind2 <= n;ind2++){
                if(s[ind1-1] == t[ind2-1]){
                    curr[ind2]=1+prev[ind2-1];
                }else{
                    curr[ind2]=0+max(prev[ind2],curr[ind2-1]);
                }           
            }
            prev=curr;
        }

        return prev[n];
    }
};