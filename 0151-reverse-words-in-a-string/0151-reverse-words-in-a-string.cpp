class Solution {
public:
    string reverseWords(string s) {
        int n=s.length();
        stack<string> st;
        string temp="";

        for(int i=0;i<n;i++){
            if(s[i] != ' '){
                temp.push_back(s[i]);
            }else{
                if(!temp.empty()){
                    st.push(temp);
                    temp="";
                }
            }
        }
        if(!temp.empty()){
            st.push(temp);
        }
        string ans="";
        ans +=st.top();
        st.pop();
        while(!st.empty()){
            ans=ans+" "+st.top();
            st.pop();
        }

        return ans;
    }
};