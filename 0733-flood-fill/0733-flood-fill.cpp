class Solution {
public:
    void dfs(vector<vector<int>>& image, int i, int j, int color, int req){
         image[i][j]=color;
         int n=image.size();
         int m=image[0].size();
         vector<int> drow={-1,1,0,0};
         vector<int> dcol={0,0,-1,1};

        for(int k=0;k<4;k++){
            int row=i+drow[k];
            int col=j+dcol[k];
            if((row >= 0 && row < n) && (col >= 0 && col < m) && image[row][col] == req && image[row][col] != color){
                image[row][col]=color;
                dfs(image,row,col,color,req);
            }
        }
         
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        int n=image.size();
        int m=image[0].size();
        //vector<vector<int>> ans(n,vector<int>(m));
        
        int reqcolor=image[sr][sc];

        if(color == reqcolor)return image;
        
        dfs(image,sr,sc,color,reqcolor);

        return image;

    }
};