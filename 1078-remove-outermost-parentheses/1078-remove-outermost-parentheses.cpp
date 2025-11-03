class Solution {
public:
    string removeOuterParentheses(string s) {
          
        int n=s.length();
        string ans="";
        int cnt_firstpar=0;
        int cnt_lastpar=0;
        int start=0;
        for(int i=0;i<n;i++){

            if(s[i] == '('){
                cnt_firstpar++;
            }else{
                cnt_lastpar++;
            }

            if(cnt_firstpar == cnt_lastpar){
                ans += s.substr(start+1,i - start - 1);
                cnt_firstpar=0;
                cnt_lastpar=0;
                start=i+1;
            }
        }
        return ans;

    }
};