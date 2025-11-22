class Solution {
private:
    bool dfs(vector<vector<int>>& graph,vector<int>& visited,vector<int>& pathvisited,int node){
         visited[node]=1;
         pathvisited[node]=1;

         for(int it:graph[node]){
            if(!visited[it]){
                if(dfs(graph,visited,pathvisited,it) == false)return false;
            }else if(pathvisited[it]){
                return false;
            }
         }
         pathvisited[node]=0;
         return true;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> visited(n,0);
        vector<int> pathvisited(n,0);
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(graph,visited,pathvisited,i);
            }
        }

        for(int i=0;i<n;i++){
            if(pathvisited[i] == 0){
               ans.push_back(i);
            }
        }

        return ans;
    }
};