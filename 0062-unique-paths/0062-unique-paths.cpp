class Solution {
private:
    int solve(int m, int n){
        if(m == 0 && n == 0)return 1;

        if(m < 0 || n < 0)return 0;

        int up=solve(m-1,n);
        int right=solve(m,n-1);

        return up+right;
    }
public:
    int uniquePaths(int m, int n) {
        vector<int> prev(n,0);

        for(int i=0;i<m;i++){
            vector<int> temp(n,0);
            for(int j=0;j<n;j++){
                if(i == 0 && j == 0)temp[j]=1;
                else{
                    int up=0;
                    int right=0;
                    if(i>0)up=prev[j];
                    if(j>0)right=temp[j-1];
                    temp[j]=up+right;
                }
            }
            prev=temp;
        }

        
        return prev[n-1];
    }
};