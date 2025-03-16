bool comp(pair<int,char> p1,pair<int,char> p2){
    return p1.first>p2.first;
}
class Solution {
public:
    
    string frequencySort(string s) {
        string ans="";
        unordered_map<char,int>mpp;
        for(int i=0;i<s.length();i++){
           mpp[s[i]]++;
        }
        vector<pair<int,char>>v;
        for(auto &it:mpp){
            v.push_back({it.second,it.first});
        }
        sort(v.begin(),v.end(),comp);
        for(auto &each:v){
            ans.append(each.first,each.second);
        }
        return ans;
    }
};