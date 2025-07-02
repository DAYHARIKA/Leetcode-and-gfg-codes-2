class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.length();
        int m=t.length();
        int l=0;
        int r=0;
        int minlen=INT_MAX;
        int start=-1;
        int cnt=0;

        int hash[256]={0};
        for(int i=0;i<m;i++)hash[t[i]]++;

        while(r < n){
            if(hash[s[r]] > 0)cnt++;
            hash[s[r]]--;

            while(cnt == m){
                if(r-l+1 < minlen){
                    start=l;
                    minlen=r-l+1;
                }
                hash[s[l]]++;
                if(hash[s[l]] > 0)cnt--;
                l++;
            }
            r++;
        }

        if(minlen == INT_MAX)return "";
        return s.substr(start,minlen);

    }
};