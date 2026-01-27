class disjointset{

    public:
    vector<int> rank,parent;

    disjointset(int n){
        rank.resize(n,0);
        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }

    int findparent(int node){
        if(parent[node] == node)return node;

        return parent[node]=findparent(parent[node]);
    }

    void unionp(int n1,int n2){
        int p1=findparent(n1);
        int p2=findparent(n2);

        if(p1 == p2)return;

        if(rank[p1] == rank[p2]){
            rank[p1]++;
            parent[p2]=p1;
        }else if(rank[p1] > rank[p2]){
            parent[p2]=p1;
        }else{
            parent[p1]=p2;
        }
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        
        int n=accounts.size();
        unordered_map<string,int> mp;
        disjointset d(n);
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string email=accounts[i][j];
                if(mp.find(email) == mp.end()){
                    mp[email]=i;
                }else{
                    d.unionp(mp[email],i);
                }
            }
        }

        vector<vector<string>> merged(n);

        for(auto it:mp){
            string email=it.first;
            int value=d.findparent(it.second);
            merged[value].push_back(email);
        }
        vector<vector<string>> ans;
        for(int i=0;i<n;i++){
            if(merged[i].size() == 0)continue;

            vector<string> temp;
            sort(merged[i].begin(),merged[i].end());
            temp.push_back(accounts[i][0]);

            for(auto it:merged[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        
        return ans;
    }
};