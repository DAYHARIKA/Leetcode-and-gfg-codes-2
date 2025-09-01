class Solution {
public:
    bool check(vector<vector<char>>& grid,vector<vector<int>> &visited,int row,int col,int n,int m){

         if((row >= 0 && row < n ) && (col >= 0 && col < m) && grid[row][col] == '1' && visited[row][col] == 0){
            return true;
         }

         return false;

    }
    void bfs(vector<vector<char>>& grid,vector<vector<int>> &visited,int r,int c,int n,int m){
         queue<pair<int,int>> q;
         q.push({r,c});
         visited[r][c]=1;

         while(!q.empty()){
            pair<int,int> node=q.front();
            q.pop();
            int row=node.first;
            int col=node.second;

            if(check(grid,visited,row+1,col,n,m)){
                visited[row+1][col]=1; 
                q.push({row+1,col});
            }

            if(check(grid,visited,row-1,col,n,m)){
                visited[row-1][col]=1; 
                q.push({row-1,col});
            }

            if(check(grid,visited,row,col+1,n,m)){
                visited[row][col+1]=1; 
                q.push({row,col+1});
            }

            if(check(grid,visited,row,col-1,n,m)){
                visited[row][col-1]=1; 
                q.push({row,col-1});
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
                    bfs(grid,visited,i,j,n,m);
                }
            }
        }

        return cnt;
    }
};