class Solution {
public:
    bool safe(int n,vector<string> &temp,int row,int col){
         
         for(int i=0;i<col;i++){
            if(temp[row][i] == 'Q')return false;
         }

         for(int i=row,j=col;i>=0 && j>=0;i--,j--){
            if(temp[i][j] == 'Q')return false;
         }

         for(int i=row,j=col;i<n && j>=0;i++,j--){
            if(temp[i][j] == 'Q')return false;
         }

         return true;
    }
    void solve(int n,vector<string> &temp,vector<vector<string>> &ans,int col){

        if(col == n){
            ans.push_back(temp);
            return;
        }

        for(int row=0;row<n;row++){
            if(safe(n,temp,row,col)){
               temp[row][col]='Q';
               solve(n,temp,ans,col+1);
               temp[row][col]='.';
            }
            
        }
         
    }
    vector<vector<string>> solveNQueens(int n) {

        vector<string> temp(n,string(n,'.'));
        
        vector<vector<string>> ans;
        solve(n,temp,ans,0);

        return ans;
    }
};