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

        vector<vector<int>> dp(n+1,vector<int>(n+1,0));

        for(int ind1=1;ind1 <= n;ind1++){
            for(int ind2=1;ind2 <= n;ind2++){
                if(s[ind1-1] == t[ind2-1]){
                    dp[ind1][ind2]=1+dp[ind1-1][ind2-1];
                }else{
                    dp[ind1][ind2]=0+max(dp[ind1-1][ind2],dp[ind1][ind2-1]);
                }           
            }
        }

        return dp[n][n];
    }
};