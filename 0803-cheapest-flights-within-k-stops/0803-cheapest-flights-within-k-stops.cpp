class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<flights.size();i++){
            int u=flights[i][0];
            int v=flights[i][1];
            int w=flights[i][2];
            adj[u].push_back({v,w});
        }

        queue<pair<int,pair<int,int>>> q;
        q.push({0,{src,0}});

        vector<int> distarr(n,1e9);

        while(!q.empty()){
            pair<int,pair<int,int>> node=q.front();
            q.pop();
            int stop=node.first;
            int val=node.second.first;
            int dist=node.second.second;
            if(stop > k)continue;
            for(auto it:adj[val]){
                int adj_val=it.first;
                int adj_w=it.second;

                if(stop <= k && distarr[adj_val] > dist+adj_w){
                    distarr[adj_val]=dist+adj_w;
                    q.push({stop+1,{adj_val,distarr[adj_val]}});
                }
            }
        }
        if(distarr[dst] == 1e9)return -1;
        return distarr[dst];
    }
};