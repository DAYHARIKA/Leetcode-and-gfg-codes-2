class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int> prev(m,0);

        for(int i=0;i<m;i++)
        prev[i]=matrix[0][i];

        for(int i=1;i<n;i++){
            vector<int> temp(m,0);
            for(int j=0;j<m;j++){

                int up=matrix[i][j]+prev[j];

                int ld=(j>0)?prev[j-1]:INT_MAX;
                if(ld != INT_MAX)ld += matrix[i][j];
                
                int rd=(j<m-1)?prev[j+1]:INT_MAX;
                if(rd != INT_MAX)rd += matrix[i][j];

                temp[j]=min({up,ld,rd});
            }
            prev=temp;
        }
        
        int mini=INT_MAX;

        for(int i=0;i<m;i++){
            mini=min(mini,prev[i]);
        }

        return mini;

    }
};