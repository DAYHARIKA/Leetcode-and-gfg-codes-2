class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {

        vector<vector<pair<int,int>>> adj(n);
        int m=(int)1e9+7;
        for(int i=0;i<roads.size();i++){
            int u=roads[i][0];
            int v=roads[i][1];
            int w=roads[i][2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }

        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
        pq.push({0,0});

        vector<long long> dist(n,1e18);
        vector<int> ways(n,0);

        dist[0]=0;
        ways[0]=1;

        while(!pq.empty()){
            pair<long long,int> node=pq.top();
            pq.pop();

            long long distnode=node.first;
            int nodeval=node.second;

            for(auto it:adj[nodeval]){
                int adjval=it.first;
                int adjw=it.second;

                if(dist[adjval] > distnode+adjw){
                    dist[adjval]=distnode+adjw;
                    pq.push({distnode+adjw,adjval});
                    ways[adjval]=ways[nodeval];
                }else if(dist[adjval] == distnode+adjw){
                    ways[adjval] = (ways[adjval]+ways[nodeval])%m;
                }
            }
        }


        return ways[n-1]%m;



    }
};