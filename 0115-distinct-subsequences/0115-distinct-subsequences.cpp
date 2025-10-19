class Solution {
private:
    int solve(string s,string t,int i,int j){
        if(j==0)return 1;
        if(i==0)return 0;

        if(s[i-1] == t[j-1]){
            return solve(s,t,i-1,j-1)+solve(s,t,i-1,j);
        }
        return solve(s,t,i-1,j);
    }
public:
    int numDistinct(string s, string t) {
        int n=s.length();
        int m=t.length();
        vector<double> curr(m+1,0);
        vector<double> prev(m+1,0);

        prev[0]=1;
        curr[0]=1;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1] == t[j-1]){
                    curr[j]=prev[j-1]+prev[j];
                }else{
                    curr[j]=prev[j];
                }  
            }
            prev=curr;
        }

        return prev[m];
    }
};