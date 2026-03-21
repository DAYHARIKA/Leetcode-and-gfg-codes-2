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
        vector<int> dp(m,INT_MAX);
        dp[0]=grid[0][0];

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                if(i==0 && j==0)continue;
                
                int up=INT_MAX;
                if(i-1 >= 0)
                up=dp[j]+grid[i][j];
                
                int left=INT_MAX;
                if(j-1 >= 0)
                left = dp[j-1]+grid[i][j];

                dp[j]=min(up,left);
            }
        }
        
        return dp[m-1];
    }
};