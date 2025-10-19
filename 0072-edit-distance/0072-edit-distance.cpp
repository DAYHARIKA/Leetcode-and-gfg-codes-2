class Solution {
private:
    int solve(string word1, string word2, int i, int j){
        
        if(j == 0)return i;
        if(i == 0)return j;

        if(word1[i-1] == word2[j-1]){
           return solve(word1,word2,i-1,j-1);
        }
        int insert=solve(word1,word2,i,j-1);
        int dele=solve(word1,word2,i-1,j);
        int replace=solve(word1,word2,i-1,j-1);

        return 1+min({insert,dele,replace});
    }
public:
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();

        vector<vector<int>> dp(n+1,vector<int>(m+1,0));

        for(int i=0;i<=n;i++)dp[i][0]=i;
        for(int j=0;j<=m;j++)dp[0][j]=j;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){

                if(word1[i-1] == word2[j-1]){
                   dp[i][j]=dp[i-1][j-1];
                }else{
                    int insert=dp[i][j-1];
                    int dele=dp[i-1][j];
                    int replace=dp[i-1][j-1];

                    dp[i][j]=1+min({insert,dele,replace});
                }
                
            }
        }

        return dp[n][m];

    }
};