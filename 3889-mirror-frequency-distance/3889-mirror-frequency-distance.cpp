class Solution {
public:
    int mirrorFrequency(string s) {

        vector<int> freq(128,0);

        for(char c:s)freq[c]++;

        vector<int> vis(128,0);
        int ans=0;
        for(char c:s){
            if(vis[c])continue;

            char m;

            if(isdigit(c)){
                m=('0'+'9')- c;
            }else{
                m=('a'+'z')- c;
            }

            ans += abs(freq[m]-freq[c]);

            vis[c]=1;
            vis[m]=1;
        }

        return ans;
    }
};