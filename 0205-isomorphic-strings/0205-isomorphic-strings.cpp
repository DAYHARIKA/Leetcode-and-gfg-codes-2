class Solution {
public:
    bool isIsomorphic(string s, string t) {
         
        int arr_s[256]={0};
        int arr_t[256]={0};

        for(int i=0;i<s.length();i++){
            if(arr_s[s[i]] == 0 && arr_t[t[i]] == 0){
                arr_s[s[i]]=t[i];
                arr_t[t[i]]=s[i];
            }else if(arr_s[s[i]] != t[i]){
                return false;
            }
        }
        return true;
    }
};