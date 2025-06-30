class Solution {
public:
    int characterReplacement(string s, int k) {

        int n=s.length();
        int hash[26]={0};
        int l=0;
        int r=0;
        int maxlen=0;
        int maxfreq=0;
        while(r<n){
            
            hash[s[r]-'A']++;
            maxfreq=max(maxfreq,hash[s[r]-'A']);
            while((r-l+1)-maxfreq > k){
                hash[s[l]-'A']--;
                maxfreq=0;
                for(int i=0;i<26;i++)
                   maxfreq=max(maxfreq,hash[i]);
                l++;
            }
            maxlen=max(maxlen,r-l+1);
            r++;
        }
        return maxlen;

    }
};