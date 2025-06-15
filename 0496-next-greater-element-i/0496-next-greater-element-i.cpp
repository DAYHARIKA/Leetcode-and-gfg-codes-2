class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
          int n=nums2.size();
          unordered_map<int,int> ans;
          stack<int> s;
          for(int i=n-1;i>=0;i--){
             
             while(!s.empty() && s.top() <= nums2[i]){
                s.pop();
             }
             if(s.empty())ans[nums2[i]]=-1;
             else ans[nums2[i]]=s.top();
             s.push(nums2[i]);
          }
          vector<int> req;
          for(int i=0;i<nums1.size();i++){
             req.push_back(ans[nums1[i]]);
          }
          return req;
    }
};