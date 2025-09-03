class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        vector<vector<int>> ans(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j] == 0){
                    q.push({{i,j},0});
                    visited[i][j]=1;
                }
            }
        }
        vector<int> arr_row={-1,1,0,0};
        vector<int> arr_col={0,0,-1,1,};
        while(!q.empty()){
            pair<pair<int,int>,int> temp=q.front();
            q.pop();
            int i=temp.first.first;
            int j=temp.first.second;
            int dist=temp.second;

            ans[i][j]=dist;

            for(int k=0;k<4;k++){
                int row=i+arr_row[k];
                int col=j+arr_col[k];

                if((row >= 0 && row < n) && (col >= 0 && col < m) && visited[row][col] != 1){
                    q.push({{row,col},dist+1});
                    visited[row][col]=1;
                }
            }
        }

        return ans;
    }
};