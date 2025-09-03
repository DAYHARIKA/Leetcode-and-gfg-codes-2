class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
       // vector<vector<int>> visited(n,vector<int>(m,0));
        vector<vector<int>> ans(n,vector<int>(m,-1));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j] == 0){
                    q.push({i,j});
                    ans[i][j]=0;
                }
            }
        }
        vector<int> arr_row={-1,1,0,0};
        vector<int> arr_col={0,0,-1,1,};
        while(!q.empty()){
            pair<int,int> temp=q.front();
            q.pop();
            int i=temp.first;
            int j=temp.second;

            for(int k=0;k<4;k++){
                int row=i+arr_row[k];
                int col=j+arr_col[k];

                if((row >= 0 && row < n) && (col >= 0 && col < m) && ans[row][col] == -1){
                    q.push({row,col});
                    ans[row][col]=ans[i][j]+1;
                }
            }
        }

        return ans;
    }
};