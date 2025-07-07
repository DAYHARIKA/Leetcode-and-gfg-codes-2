class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
          
          int n=matrix.size();
          int m=matrix[0].size();

          int cnt=0;
          int total=n*m;

          int l=0;
          int r=m-1;
          int t=0;
          int b=n-1;
          vector<int> ans;
          while(cnt < total){

             for(int i=l;i<=r&&cnt<total;i++){       
                 ans.push_back(matrix[t][i]);
                 cnt++;
             }
             t++;

             for(int i=t;i<=b&&cnt<total;i++){
                 ans.push_back(matrix[i][r]);
                 cnt++;
             }
             r--;

             for(int i=r;i>=l&&cnt<total;i--){
                ans.push_back(matrix[b][i]);
                cnt++;
             }
            b--;
             for(int i=b;i>=t&&cnt<total;i--){
                ans.push_back(matrix[i][l]);
                cnt++;
             }
             l++;
          }
          return ans;
    }
};