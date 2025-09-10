class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,0}});

        vector<vector<int>> dist(n,vector<int>(m,1e9));
        dist[0][0]=0;
        vector<int> drow={0,0,-1,1};
        vector<int> dcol={-1,1,0,0};
        while(!pq.empty()){
            pair<int,pair<int,int>> node=pq.top();
            pq.pop();

            int diff=node.first;
            int i=node.second.first;
            int j=node.second.second;

            for(int k=0;k<4;k++){
                int newr=i+drow[k];
                int newc=j+dcol[k];

                if((newr >= 0 && newr < n) && (newc >= 0 && newc < m)){
                    int maxi=max(abs(heights[i][j]-heights[newr][newc]),diff);
                    if(dist[newr][newc] > maxi){
                        dist[newr][newc]=maxi;
                        pq.push({maxi,{newr,newc}});
                    }
                }
            }
        }
        return dist[n-1][m-1];

    }
};