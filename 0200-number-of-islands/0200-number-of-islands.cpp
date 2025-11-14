class Solution {
public:
    
    void dfs(vector<vector<char>>& grid,vector<vector<int>> &visited,int r,int c,int n,int m){
        visited[r][c]=1;
         
        vector<int> row={0,0,-1,1};
        vector<int> col={-1,1,0,0};

        for(int i=0;i<4;i++){
            int newr=r+row[i];
            int newc=c+col[i];
            if((newr >= 0 && newr < n ) && (newc >= 0 && newc < m) && grid[newr][newc] == '1' && visited[newr][newc] == 0){
                dfs(grid,visited,newr,newc,n,m);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        //visited array
        vector<vector<int>> visited(n,vector<int>(m,0));
        int cnt=0;
        

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j] != 1 && grid[i][j] == '1'){
                    cnt++;
                    dfs(grid,visited,i,j,n,m);
                }
            }
        }

        return cnt;
    }
};