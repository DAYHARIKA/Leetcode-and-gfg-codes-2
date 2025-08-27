class compare{
public:
   bool operator()(pair<int,int> a,pair<int,int> b){
        return a.second>b.second;
   }
};
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        vector<int> ans;
        priority_queue<pair<int,int>,vector<pair<int,int>>,compare> pq;
        for(auto it:mp){
            pq.push({it.first,it.second});
            if(pq.size() > k){
                pq.pop();
            }
        }
        while(!pq.empty()){
            ans.push_back(pq.top().first);
            pq.pop();
        }
        return ans;
    }
};