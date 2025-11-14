class Solution {
public:
    bool check(vector<vector<char>>& grid,vector<vector<int>> &visited,int row,int col,int n,int m){

         if((row >= 0 && row < n ) && (col >= 0 && col < m) && grid[row][col] == '1' && visited[row][col] == 0){
            return true;
         }

         return false;

    }
    void dfs(vector<vector<char>>& grid,vector<vector<int>> &visited,int r,int c,int n,int m,vector<int> &row,vector<int> &col){
         visited[r][c]=1;

         for(int i=0;i<4;i++){
            int newr=r+row[i];
            int newc=c+col[i];
            if(check(grid,visited,newr,newc,n,m)){
                dfs(grid,visited,newr,newc,n,m,row,col);
            }
         }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        //visited array
        vector<vector<int>> visited(n,vector<int>(m,0));
        int cnt=0;
        vector<int> row={0,0,-1,1};
        vector<int> col={-1,1,0,0};

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j] != 1 && grid[i][j] == '1'){
                    cnt++;
                    dfs(grid,visited,i,j,n,m,row,col);
                }
            }
        }

        return cnt;
    }
};