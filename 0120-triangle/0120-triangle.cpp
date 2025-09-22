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
        vector<int> prev(n,0);

        for(int i=0;i<n;i++){
            prev[i]=triangle[n-1][i];
        }

        for(int i=n-2;i>=0;i--){
            vector<int> temp(n,0);
            for(int j=i;j>=0;j--){
                int down=triangle[i][j]+prev[j];
                int diag=triangle[i][j]+prev[j+1];

                temp[j]=min(down,diag);
            }
            prev=temp;
        }

        
        return prev[0];
    }
};