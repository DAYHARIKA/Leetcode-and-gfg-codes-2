class Solution {
public:
    string reverseWords(string s) {
        int n=s.length();
        string ans="";
        string temp="";

        for(int i=0;i<n;i++){
            if(s[i] != ' '){
                temp.push_back(s[i]);
            }else{
                if(!temp.empty()){
                    if(ans.empty()){
                        ans=temp;
                    }else{
                        ans=temp+" "+ans;
                    }
                    temp="";
                }
            }
        }
        if(!temp.empty()){
            if(ans.empty()){
                ans=temp;
            }else{
                ans=temp+" "+ans;
            }
        }
        
        return ans;
    }
};