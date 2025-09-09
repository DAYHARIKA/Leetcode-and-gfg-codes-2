class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        //Time : n * n
        //Space : n * n + 

        //dimensions
        int n=grid.size();
        
        //base condition 
        if(n==1 && grid[0][0]==0) return 1;
        if(grid[0][0]!=0 || grid[n-1][n-1]!=0) return -1;
        
        //possible directions
        vector<vector<int>> directions={{-1,-1},{-1,0},{-1,1},
        {0,-1},{0,1},{1,-1},{1,0},{1,1}};

        //initialising a distance array
         vector<vector<int>> dist(n,vector<int> (n,1e9));

        //queue for bfs traversal
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{0,0}});
        
        //traversal
        while(!q.empty()){
            int x=q.front().second.first;
            int y=q.front().second.second;
            int dis=q.front().first;
            q.pop();
            
            //traversing possible paths
            for(auto it : directions){
                int newx=x-it[0];
                int newy=y-it[1];

                if(newx >=0 && newy >=0 && newx < n && newy < n 
                && grid[newx][newy]==0){
                   int distance=dis+1;
                   if(dist[newx][newy] > distance){
                      dist[newx][newy]=distance;
                      q.push({distance,{newx,newy}});
                      if(newx==n-1 && newy==n-1) 
                      return dist[n-1][n-1]+1;
                   }
                }
            }
        }

        return -1;
    }
};