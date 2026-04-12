class Solution {
public:
    int solve(vector<int>& arr,int i,int j,vector<vector<int>> &dp){
        
        if(i > j)return 0;

        if(dp[i][j] != -1)return dp[i][j];

        int mini=INT_MAX;
        for(int ind=i;ind <= j;ind++){

            int cost=(arr[j+1]-arr[i-1])+solve(arr,i,ind-1,dp)+solve(arr,ind+1,j,dp);
            mini=min(mini,cost);

        }
        return dp[i][j]=mini;

    }
    int minCost(int n, vector<int>& cuts) {
        
        int c=cuts.size();
        cuts.push_back(0);
        cuts.push_back(n);

        sort(cuts.begin(),cuts.end());

        int m=cuts.size();

        vector<vector<int>> dp(m,vector<int>(m,0));

        for(int i=c;i>=1;i--){
            for(int j=1;j<=c;j++){
                
                if(i > j)continue;

                int mini=INT_MAX;
                for(int ind=i;ind <= j;ind++){

                    int cost=(cuts[j+1]-cuts[i-1])+dp[i][ind-1]+dp[ind+1][j];
                    mini=min(mini,cost);

                }
                dp[i][j]=mini;

            }
        }

        return dp[1][c];

    }
};