class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);

        for(int i=0;i<prerequisites.size();i++){
            int u=prerequisites[i][0];
            int v=prerequisites[i][1];
            adj[v].push_back(u);
        }

        vector<int> indegree(numCourses,0);
        queue<int> q;
        for(int i=0;i<prerequisites.size();i++){
            int v=prerequisites[i][0];
            indegree[v]++;
        }
        for(int i=0;i<numCourses;i++){
            if(indegree[i] == 0){
            q.push(i);
            }
        }
        int cnt=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            cnt++;
            
            for(int it:adj[node]){
                indegree[it]--;
                if(indegree[it] == 0)q.push(it);
            }
        }
        
        if(cnt == numCourses)return true;
        
        return false;
    }
};