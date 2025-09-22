class Solution {
private:
    int solve(vector<vector<int>>& triangle,int n,int i,int j){
        if(i == n-1){
            return triangle[n-1][j];
        }

        int down=triangle[i][j]+solve(triangle,n,i+1,j);
        int diag=triangle[i][j]+solve(triangle,n,i+1,j+1);

        return min(down,diag);
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,0));

        for(int i=0;i<n;i++){
            dp[n-1][i]=triangle[n-1][i];
        }

        for(int i=n-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                int down=triangle[i][j]+dp[i+1][j];
                int diag=triangle[i][j]+dp[i+1][j+1];

                dp[i][j]=min(down,diag);
            }
        }

        
        return dp[0][0];
    }
};