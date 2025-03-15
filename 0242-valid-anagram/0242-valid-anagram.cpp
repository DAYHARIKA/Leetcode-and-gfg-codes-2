class Solution {
public:
    bool isAnagram(string s, string t) {

         if(s.length() != t.length())return false;
         int arr1[256]={0};
         for(int i=0;i<s.length();i++){
            arr1[s[i]]++;
         }
         for(int i=0;i<t.length();i++){
            arr1[t[i]]--;
         }
         for(int i=0;i<s.length();i++){
            if(arr1[s[i]] != 0)return false;
         }
         return true;
    }
};