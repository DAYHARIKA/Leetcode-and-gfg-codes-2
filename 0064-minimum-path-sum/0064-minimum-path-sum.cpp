class Solution {
private:
    int solve(vector<vector<int>>& grid,int i,int j){
        if(i == 0 && j == 0)return grid[0][0];

        if(i<0 || j<0)return INT_MAX;
        
        int up = solve(grid,i-1,j);   
        int left = solve(grid,i,j-1);

        return grid[i][j]+min(up,left);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,INT_MAX));
        dp[0][0]=grid[0][0];

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                if(i==0 && j==0)continue;

                int up=(i>0)?dp[i-1][j]:INT_MAX;
                if(up != INT_MAX)up += grid[i][j];
                
                int left=(j>0)?dp[i][j-1]:INT_MAX;
                if(left != INT_MAX)left += grid[i][j];

                dp[i][j]=min(up,left);
            }
        }
        
        return dp[n-1][m-1];
    }
};