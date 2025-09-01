class Solution {
private:
    void dfs(vector<vector<int>>& adj,vector<int>& visited,int node){
         visited[node]=1;
         for(int it:adj[node]){
            if(!visited[it]){
                dfs(adj,visited,it);
            }
         }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
         int v=isConnected.size();
         vector<vector<int>> adj(v);
        //creating adjacency list
         for(int i=0;i<v;i++){
             for(int j=0;j<v;j++){
                if(isConnected[i][j] == 1 && i != j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
             }
         }
         //doing traversal of dfs
         vector<int> visited(v,0);
         int cnt=0;
         for(int i=0;i<v;i++){
             if(!visited[i]){
                cnt++;
                dfs(adj,visited,i);
             }
         }

         return cnt;
    }
};