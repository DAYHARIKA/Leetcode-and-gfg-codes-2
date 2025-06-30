class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int> ans;
        int n=grid.size();

        long long val=n*n;

        long long sum=(val*(val+1))/2;
        long long square=(val*(val+1)*(2*val+1))/6;
        long long sum1=0;
        long long square1=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                sum1=sum1+grid[i][j];
                square1=square1+(grid[i][j]*grid[i][j]);
            }
        }
        long long val1=sum-sum1;
        long long val2=square-square1;
         
        val2=val2/val1;

        int miss=(val1+val2)/2;
        int repeat=miss-val1;

        ans.push_back(repeat);
        ans.push_back(miss);

        return ans;
    }
};