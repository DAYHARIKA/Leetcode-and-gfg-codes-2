class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        int n=image.size();
        int m=image[0].size();
        vector<vector<int>> visit(n,vector<int>(m,0));
        vector<vector<int>> ans(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans[i][j]=image[i][j];
            }
        }

        queue<pair<int,int>> q;
        int reqcolor=image[sr][sc];
        q.push({sr,sc});
        visit[sr][sc]=1;
        ans[sr][sc]=color;
        
        vector<int> drow={-1,1,0,0};
        vector<int> dcol={0,0,-1,1};
        while(!q.empty()){
            pair<int,int> node=q.front();
            q.pop();
            int i=node.first;
            int j=node.second;
            for(int k=0;k<4;k++){
                int row=i+drow[k];
                int col=j+dcol[k];
                if((row >= 0 && row < n) && (col >= 0 && col < m) && visit[row][col] != 1 && image[row][col] == reqcolor){
                    q.push({row,col});
                    visit[row][col]=1;
                    ans[row][col]=color;
                }
            }
        }

        return ans;

    }
};