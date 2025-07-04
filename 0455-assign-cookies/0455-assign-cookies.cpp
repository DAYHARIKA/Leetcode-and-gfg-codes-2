class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n=g.size();
        int m=s.size();
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int l=0;
        int r=0;
        while(l<m && r<n){

            if(s[l] >= g[r]){
                l++;
                r++;
            }else{
                l++;
            }
        }
        return r;
    }
};