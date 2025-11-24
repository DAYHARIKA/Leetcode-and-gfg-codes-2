class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        if(n==1 && m==1 && grid[0][0] == 0)return 1;
        if(grid[0][0] != 0 || grid[n-1][m-1] != 0)return -1;
        vector<vector<int>> vdist(n,vector<int>(m,1e9));
        queue<pair<int,pair<int,int>>> q;
        q.push({1,{0,0}});
        vdist[0][0]=1;
        vector<int> dx={1,-1,0,0,1,1,-1,-1};
        vector<int> dy={0,0,1,-1,1,-1,1,-1};  
        while(!q.empty()){
           pair<int,pair<int,int>> node=q.front();
           q.pop();

           int dist=node.first;
           int i=node.second.first;
           int j=node.second.second;

           for(int k=0;k<8;k++){
               int newr=i+dx[k];
               int newc=j+dy[k];

               if((newr >= 0 && newr < n) && (newc >= 0 && newc < m) && grid[newr][newc] == 0 && vdist[newr][newc] > vdist[i][j]+1){
                  if(newr == n-1 && newc == m-1)return vdist[i][j]+1;
                  vdist[newr][newc]=vdist[i][j]+1;
                  q.push({vdist[newr][newc],{newr,newc}});
               }
           }
        
        }

        return -1;
    }
};