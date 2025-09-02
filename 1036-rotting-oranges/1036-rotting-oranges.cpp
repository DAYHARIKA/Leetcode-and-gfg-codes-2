class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> visit(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                if(grid[i][j] == 2){
                    q.push({{i,j},0});
                    visit[i][j]=1;
                }
                 

            }
        }

        int time=0;
        vector<int> drow={-1,1,0,0};
        vector<int> dcol={0,0,-1,1};
        while(!q.empty()){
            pair<pair<int,int>,int> node=q.front();
            q.pop();
            int i=node.first.first;
            int j=node.first.second;
            int t=node.second;
            time=max(time,t);

           for(int k=0;k<4;k++){
              int row=i+drow[k];
              int col=j+dcol[k];

              if((row >= 0 && row < n) && (col>=0 && col < m) && visit[row][col] != 1 && grid[row][col] != 0){
                 q.push({{row,col},t+1});
                 visit[row][col]=1;
              }
           }

        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] >= 1 && visit[i][j] != 1)return -1;
            }
        }

        return time;
        
    }
};