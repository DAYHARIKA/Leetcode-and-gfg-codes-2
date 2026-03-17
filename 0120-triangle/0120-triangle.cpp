class Solution {
public:
    int solve(vector<vector<int>>& triangle,int i,int j){

        if(i == triangle.size()-1){
            return triangle[i][j];
        }

        int s=triangle[i][j]+solve(triangle,i+1,j);
        int d=triangle[i][j]+solve(triangle,i+1,j+1);


        return min(s,d);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int n=triangle.size();
  
        vector<int> curr(n,0);

        for(int i=0;i<n;i++){
            curr[i]=triangle[n-1][i];
        }
        
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<=i;j++){

                int s=triangle[i][j]+curr[j];
                int d=triangle[i][j]+curr[j+1];

                curr[j]=min(s,d);
            }
        }
        

        return curr[0];
    }
};