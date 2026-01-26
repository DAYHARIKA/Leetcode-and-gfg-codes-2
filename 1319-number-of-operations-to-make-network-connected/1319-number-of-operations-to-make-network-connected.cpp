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
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        int len=connections.size();
        if(len < n-1)return -1;
        disjointset d(n);
        int ans=0;
        for(int i=0;i<connections.size();i++){
            int u=connections[i][0];
            int v=connections[i][1];
            d.unionp(u,v); 
        }

        for(int i=0;i<n;i++){
            if(d.findparent(i) == i)ans++;
        }

        return ans-1;
    }
};