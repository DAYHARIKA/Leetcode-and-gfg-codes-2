class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans=0;
        stack<int> st;
        for(int i=0;i<heights.size();i++){
            
            while(!st.empty() && heights[st.top()]> heights[i]){
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
    int maximalRectangle(vector<vector<char>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();
        vector<vector<int>> temp(row,vector<int>(col,0));
        for(int i=0;i<col;i++){
            int sum=0;
            for(int j=0;j<row;j++){

                if(matrix[j][i] == '0'){
                    sum=0;
                }else{
                    sum += matrix[j][i]-'0';
                }
                temp[j][i]=sum;
            }
            
        }
        int maxi=0;
        for(int i=0;i<row;i++){
            int largest=largestRectangleArea(temp[i]);
            maxi=max(maxi,largest);
        }
        return maxi;
    }
};