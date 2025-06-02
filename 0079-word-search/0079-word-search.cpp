class Solution {
public:
    bool solve(vector<vector<char>>& board, string word,vector<vector<int>>& visited,int i,int j,int n,int m,int ind){
        if(ind == word.length())return true;
         if(i<0 || i>=n || j<0 || j>=m || board[i][j] != word[ind] || visited[i][j] ==1){
            return false;
         }
         visited[i][j]=1;
         if(solve(board,word,visited,i+1,j,n,m,ind+1)||
            solve(board,word,visited,i-1,j,n,m,ind+1)||
            solve(board,word,visited,i,j+1,n,m,ind+1)||
            solve(board,word,visited,i,j-1,n,m,ind+1))return true;
         visited[i][j]=0;
         return false;
        
    }
    bool exist(vector<vector<char>>& board, string word) {
         int row=board.size();
         int col=board[0].size();
         vector<vector<int>> visited(row,vector<int>(col,0));
         for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(solve(board,word,visited,i,j,row,col,0))return true;
            }
         }
         return false;
    }
};