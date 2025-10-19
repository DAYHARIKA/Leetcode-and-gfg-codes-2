class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {

        int n=str1.length();
        int m=str2.length();

        vector<vector<int>> dp(n+1,vector<int>(m+1,0));

        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(str1[i-1] == str2[j-1])dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=0+max(dp[i][j-1],dp[i-1][j]);
            }
        }

        int len=(n+m)-dp[n][m];

        string ans(len,'$');

        int i=n;
        int j=m;
        int ind=len-1;
        
        while(i > 0 && j > 0){
            if(str1[i-1] == str2[j-1]){
                ans[ind]=str1[i-1];
                ind--;
                i=i-1;
                j=j-1;
            }else if(dp[i-1][j] > dp[i][j-1]){
                ans[ind]=str1[i-1];
                ind=ind-1;
                i=i-1;
            }else{
                ans[ind]=str2[j-1];
                ind=ind-1;
                j=j-1;
            }
        }
        while(i>0){
            ans[ind]=str1[i-1];
            ind=ind-1;
            i=i-1;
        }
        while(j>0){
            ans[ind]=str2[j-1];
            ind=ind-1;
            j=j-1;
        }
        return ans;   
    }
};