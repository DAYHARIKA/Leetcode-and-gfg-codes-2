class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<vector<pair<int,int>>> adj(n+1);
        for(int i=0;i<times.size();i++){
            int u=times[i][0];
            int v=times[i][1];
            int w=times[i][2];
            adj[u].push_back({v,w});
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,k});
        
        vector<int> darr(n+1,1e9);
        darr[k]=0;

        while(!pq.empty()){
            pair<int,int> node=pq.top();
            pq.pop();

            int dist=node.first;
            int val=node.second;

            for(auto it:adj[val]){
                int adj_val=it.first;
                int adj_w=it.second;

                if(darr[adj_val] > dist+adj_w){
                    darr[adj_val] = dist+adj_w;
                    pq.push({darr[adj_val],adj_val});
                }
            }
        }
        int maxi=0;
        for(int i=1;i<=n;i++){
            if(darr[i] == 1e9)return -1;
            maxi=max(maxi,darr[i]);
        }

        return maxi;
    }
};