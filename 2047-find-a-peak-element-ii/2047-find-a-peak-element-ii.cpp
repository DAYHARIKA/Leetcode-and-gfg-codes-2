class Solution {
public:
    int maxi(vector<vector<int>>& mat,int n,int m,int col){

        int max_ele=INT_MIN;
        int max_ind=-1;
        for(int i=0;i<n;i++){
            if(mat[i][col] > max_ele){
                max_ele=mat[i][col];
                max_ind=i;
            }
        }
        return max_ind;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
          
        int n=mat.size();
        int m=mat[0].size();
        int low=0;
        int high=m-1;
        while(low <= high){
            int mid=(low+high)/2;
            int row=maxi(mat,n,m,mid);
            int left=(mid-1 >= 0)?mat[row][mid-1]:-1;
            int right=(mid+1 < m)?mat[row][mid+1]:-1;
            if(mat[row][mid] > left && mat[row][mid] > right){
              return {row,mid};
            }else if(mat[row][mid] < right){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return {-1,-1};
    }
};