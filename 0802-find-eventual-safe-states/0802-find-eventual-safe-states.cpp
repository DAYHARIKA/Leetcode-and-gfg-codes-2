class Solution {
private:
    bool dfs(vector<vector<int>>& graph,vector<int>& visited,int node){
         visited[node]=1;

         for(int it:graph[node]){
            if(visited[it] == 0){
                if(dfs(graph,visited,it) == false)return false;
            }else if(visited[it] == 1){
                return false;
            }
         }
         visited[node]=2;
         return true;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> visited(n,0);
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(graph,visited,i);
            }
        }

        for(int i=0;i<n;i++){
            if(visited[i] == 2){
               ans.push_back(i);
            }
        }

        return ans;
    }
};