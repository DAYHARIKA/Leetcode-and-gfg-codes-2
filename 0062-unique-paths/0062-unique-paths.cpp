class Solution {
public:
    int uniquePaths(int m, int n) {
        
        vector<int> curr(n,0);
        vector<int> prev(n,0);

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i== 0 && j==0)curr[0]=1;
                else{
                    int left=0;
                    if(j-1 >= 0)left=curr[j-1];
                    int up=0;
                    if(i-1 >= 0)up=prev[j];

                    curr[j]=left+up;
                }
            }
            prev=curr;
        }

        return prev[n-1];
    }
};