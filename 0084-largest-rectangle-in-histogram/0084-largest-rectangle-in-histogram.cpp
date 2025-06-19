class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans=0;
        stack<int> st;
        for(int i=0;i<heights.size();i++){
            
            while(!st.empty() && heights[st.top()] > heights[i]){
                int ele=heights[st.top()];
                st.pop();
                int nse=i;
                int pse=st.empty()?-1:st.top();
                ans=max(ans,ele*(nse-pse-1));
            }
            st.push(i);
        }

        while(!st.empty()){

            int ele=heights[st.top()];
            st.pop();
            int nse=heights.size();
            int pse=st.empty()?-1:st.top();
            ans=max(ans,ele*(nse-pse-1));
        }
        return ans;
    }
};