class Solution {
private:
    bool dfs(vector<vector<int>>& graph,vector<int>& arr,int node){
        //  arr[node]=color;

         for(int it:graph[node]){
             if(arr[it] == -1){
                arr[it]=!arr[node];
                if(dfs(graph,arr,it) == false)return false;//not biaratite
             }else if(arr[it] == arr[node]){
                return false;
             }
         }

         return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
         
        int n=graph.size();
        vector<int> arr(n,-1);
        for(int i=0;i<n;i++){
            if(arr[i] == -1){
                arr[i]=0;
                if(dfs(graph,arr,i) == false)return false;
            }
        }

        return true;
    }
};