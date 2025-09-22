class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m,INT_MAX));

        for(int i=0;i<m;i++)
        dp[0][i]=matrix[0][i];

        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){

                int up=matrix[i][j]+dp[i-1][j];

                int ld=(j>0)?dp[i-1][j-1]:INT_MAX;
                if(ld != INT_MAX)ld += matrix[i][j];
                
                int rd=(j<m-1)?dp[i-1][j+1]:INT_MAX;
                if(rd != INT_MAX)rd += matrix[i][j];

                dp[i][j]=min({up,ld,rd});
            }
        }
        
        int mini=INT_MAX;

        for(int i=0;i<m;i++){
            mini=min(mini,dp[n-1][i]);
        }

        return mini;

    }
};