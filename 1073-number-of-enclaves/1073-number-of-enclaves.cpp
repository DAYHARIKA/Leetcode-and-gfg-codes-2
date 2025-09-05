class Solution {
    void dfs(vector<vector<int>>& grid,vector<vector<int>>& visit,int i,int j, vector<int> drow,vector<int> dcol){
         visit[i][j]=1;
         int n=grid.size();
         int m=grid[0].size();
         for(int k=0;k<4;k++){
            int row=i+drow[k];
            int col=j+dcol[k];
            if((row >=0 && row < n) && (col >= 0 && col < m) && grid[row][col] == 1 && !visit[row][col]){
                dfs(grid,visit,row,col,drow,dcol);
            }
         }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> visit(n,vector<int>(m,0));
        vector<int> drow={-1,1,0,0};
        vector<int> dcol={0,0,-1,1};
        for(int i=0;i<m;i++){
            if(grid[0][i] == 1 && !visit[0][i]){
               dfs(grid,visit,0,i,drow,dcol);
            }

            if(grid[n-1][i] == 1 && !visit[n-1][i]){
               dfs(grid,visit,n-1,i,drow,dcol);
            }
        }

        for(int i=0;i<n;i++){
            if(grid[i][0] == 1 && !visit[i][0]){
               dfs(grid,visit,i,0,drow,dcol);
            }
            if(grid[i][m-1] == 1 && !visit[i][m-1]){
               dfs(grid,visit,i,m-1,drow,dcol); 
            }
        }
        int cnt=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1 && !visit[i][j]){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};