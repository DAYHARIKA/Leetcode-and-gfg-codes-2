class Solution {
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