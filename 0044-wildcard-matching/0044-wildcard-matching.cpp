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

        vector<bool> prev(m+1,false);
        vector<bool> curr(m+1,false);

        prev[0]=true;

        for(int j=1;j<=m;j++){
            int flag=true;
            for(int k=1;k<=j;k++){
                if(p[k-1] != '*'){
                    flag=false;
                    break;
                }
            }
            prev[j]=flag;
        }


        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1] == p[j-1] || p[j-1] == '?'){
                    curr[j]=prev[j-1];
                }else if(p[j-1] == '*'){
                    curr[j]=(curr[j-1] || prev[j]);
                }else{
                    curr[j]=false;
                } 
            }
            prev=curr;
        }
        return prev[m];
    }
};