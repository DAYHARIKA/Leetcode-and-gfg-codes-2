class Solution {
public:
    bool isAnagram(string s, string t) {
         if(s.length() != t.length())return false;

         int hashs[26]={0};
         int hasht[26]={0};

         for(int i=0;i<s.length();i++){
            hashs[s[i]-'a']++;
            hasht[t[i]-'a']++;
         }

         for(int i=0;i<s.length();i++){
            if(hashs[s[i]-'a'] != hasht[s[i]-'a'])return false;
         }

         return true;
    }
};