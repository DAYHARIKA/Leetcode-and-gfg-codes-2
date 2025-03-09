class Solution {
public:
    string reverseWords(string s) {
        
          int n=s.length();
          string temp="";
          string ans="";
          for(int i=0;i<n;i++){
             if(s[i] != ' '){
                temp += s[i];
             }else{
                if(!temp.empty()){
                    if(!ans.empty()){
                        ans=temp+" "+ans;
                    }else{
                        ans=temp;
                    }
                    temp="";
                }
             }
          }

          if(!temp.empty()){
            if(!ans.empty()){
                ans=temp+" "+ans;
            }else{
                ans=temp;
            }
          }
          return ans;
    }
};