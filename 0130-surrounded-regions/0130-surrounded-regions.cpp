class Solution {
private:
    void dfs(vector<vector<char>>& board,vector<vector<int>> &visit,int i,int j,vector<int> &drow,vector<int> &dcol){
         
        visit[i][j]=1;

        int n=board.size();
        int m=board[0].size();

        for(int k=0;k<4;k++){
            int row=i+drow[k];
            int col=j+dcol[k];
            if((row >= 0 && row < n) && (col >= 0 && col < m) && board[row][col] == 'O' && visit[row][col] != 1){
                dfs(board,visit,row,col,drow,dcol);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>> visit(n,vector<int>(m,0));
        vector<int> drow={-1,1,0,0};
        vector<int> dcol={0,0,-1,1};

        for(int i=0;i<m;i++){
            if(!visit[0][i] && board[0][i] == 'O'){
                dfs(board,visit,0,i,drow,dcol);
            }

            if(!visit[n-1][i] && board[n-1][i] == 'O'){
                 dfs(board,visit,n-1,i,drow,dcol);
            }
        }

        for(int i=0;i<n;i++){
            if(!visit[i][0] && board[i][0] == 'O'){
                dfs(board,visit,i,0,drow,dcol);
            }

            if(!visit[i][m-1] && board[i][m-1] == 'O'){
                dfs(board,visit,i,m-1,drow,dcol);
            }
        }


        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visit[i][j] && board[i][j] == 'O'){
                    board[i][j]='X';
                }
            }
        }

    }
};