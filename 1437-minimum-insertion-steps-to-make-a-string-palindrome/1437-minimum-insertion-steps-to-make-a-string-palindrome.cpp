class Solution {
private:
    int solve(string s,int ind1,int ind2,vector<vector<int>>& dp){
        if(ind1 >= ind2){
            return 0;
        }

        if(dp[ind1][ind2] != -1)return dp[ind1][ind2];

        if(s[ind1] == s[ind2]){
            return dp[ind1][ind2]=solve(s,ind1+1,ind2-1,dp);
        }

        return dp[ind1][ind2]=1+min(solve(s,ind1,ind2-1,dp),solve(s,ind1+1,ind2,dp));
    }
public:
    int minInsertions(string s) {  
        int n=s.length();
        vector<vector<int>> dp(n,vector<int>(n,0));

        for(int ind1=n-1;ind1>=0;ind1--){
            for(int ind2=ind1+1;ind2<n;ind2++){
                if(s[ind1] == s[ind2]){
                    dp[ind1][ind2]=dp[ind1+1][ind2-1];
                }else{
                    dp[ind1][ind2]=1+min(dp[ind1][ind2-1],dp[ind1+1][ind2]);
                }   
            }
        }
        return dp[0][n-1];
    }
};