class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {

        vector<vector<int>> mat(n,vector<int>(n,1e9));
        vector<vector<pair<int,int>>> adj(n);

        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int w=edges[i][2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }


        //priority queue
        for(int i=0;i<n;i++){
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
            pq.push({0,i});
            mat[i][i]=0;
            while(!pq.empty()){
                auto it=pq.top();
                pq.pop();

                int dist=it.first;
                int node=it.second;

                for(auto it:adj[node]){
                    int adj_node=it.first;
                    int adj_dist=it.second;
                    if(mat[i][adj_node] > dist+adj_dist){
                        mat[i][adj_node]=dist+adj_dist;
                        pq.push({mat[i][adj_node],adj_node});
                    }
                }
            }
        }
        int cnt=n;
        int node=-1;
        

        for(int i=0;i<n;i++){
            int temp=0;
            for(int j=0;j<n;j++){
                if(mat[i][j] <= distanceThreshold)temp++;
            }
            if(temp <= cnt){
                cnt=temp;
                node=i;
            }
        }

        return node;
    }
};