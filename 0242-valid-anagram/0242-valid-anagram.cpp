class Solution {
public:
    bool isAnagram(string s, string t) {

         if(s.length() != t.length())return false;
         int arr1[256]={0};
         int arr2[256]={0};
         for(int i=0;i<s.length();i++){
            arr1[s[i]]++;
            arr2[t[i]]++;
         }
         for(int i=0;i<s.length();i++){
            if(arr1[s[i]] != arr2[s[i]])return false;
         }
         return true;
    }
};