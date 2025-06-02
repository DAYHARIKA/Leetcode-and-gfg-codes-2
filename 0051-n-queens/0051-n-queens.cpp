class Solution {
public:
    bool check(int n,vector<string>& board,int row,int col){
        for(int i=0;i<row;i++){
            if(board[i][col] == 'Q')return false;
        }
        for(int i=row,j=col;i>=0&&j>=0;i--,j--){
            if(board[i][j] == 'Q')return false;
        }
        for(int i=row,j=col;i>=0&&j<n;i--,j++){
            if(board[i][j] == 'Q')return false;
        }
        return true;
    }
    void solve(int n,vector<vector<string>>& ans,vector<string>& board,int row){

        if(row == n){
            ans.push_back(board);
            return;
        }
        for(int col=0;col<n;col++){
            if(check(n,board,row,col)){
                board[row][col]='Q';
                solve(n,ans,board,row+1);
                board[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {

        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        solve(n,ans,board,0);
        return ans;

    }
};