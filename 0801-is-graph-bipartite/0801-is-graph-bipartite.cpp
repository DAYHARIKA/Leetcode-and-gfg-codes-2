class Solution {
private:
    bool dfs(vector<vector<int>>& graph,vector<int>& arr,int node,int color){
         arr[node]=color;

         for(int it:graph[node]){
             if(arr[it] == -1){
                if(dfs(graph,arr,it,!color))return true;//not biaratite
             }else if(arr[it] == color){
                return true;
             }
         }

         return false;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
         
        int n=graph.size();
        vector<int> arr(n,-1);
        for(int i=0;i<n;i++){
            if(arr[i] == -1){
                if(dfs(graph,arr,i,0))return false;
            }
        }

        return true;
    }
};