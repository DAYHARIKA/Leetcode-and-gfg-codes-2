class Solution {
private:
   bool solve(string s,string p,int i,int j){

        if(i == 0 && j == 0)return true;

        if(i > 0 && j == 0)return false;

        if(i == 0 && j>0){
            for(int k=1;k<=j;k++){
                if(p[k-1] != '*')return false;
            }
            return true;
        }
        
        if(s[i-1] == p[j-1] || p[j-1] == '?'){
            return solve(s,p,i-1,j-1);
        }else if(p[j-1] == '*'){
            return (solve(s,p,i,j-1) || solve(s,p,i-1,j));
        }else{
            return false;
        }
   }
public:
    bool isMatch(string s, string p) {
        int n=s.length();
        int m=p.length();

        vector<vector<bool>> dp(n+1,vector<bool>(m+1,false));

        dp[0][0]=true;

        for(int j=1;j<=m;j++){
            int flag=true;
            for(int k=1;k<=j;k++){
                if(p[k-1] != '*'){
                    flag=false;
                    break;
                }
            }
            dp[0][j]=flag;
        }


        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1] == p[j-1] || p[j-1] == '?'){
                    dp[i][j]=dp[i-1][j-1];
                }else if(p[j-1] == '*'){
                    dp[i][j]=(dp[i][j-1] || dp[i-1][j]);
                }else{
                    dp[i][j]=false;
                } 
            }
        }
        return dp[n][m];
    }
};