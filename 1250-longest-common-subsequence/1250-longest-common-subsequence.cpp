class Solution {
private:
    int solve(string text1, string text2,int i,int j){
        if(i == 0 || j == 0)return 0;

        if(text1[i-1] == text2[j-1])return 1+solve(text1,text2,i-1,j-1);
        else return 0+max(solve(text1,text2,i,j-1),solve(text1,text2,i-1,j));
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));

        for(int i=0;i<m+1;i++)dp[0][i]=0;
        for(int i=0;i<=n;i++)dp[i][0]=0;

        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(text1[i-1] == text2[j-1])dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=0+max(dp[i][j-1],dp[i-1][j]);
            }
        }

        return dp[n][m];
    }
};