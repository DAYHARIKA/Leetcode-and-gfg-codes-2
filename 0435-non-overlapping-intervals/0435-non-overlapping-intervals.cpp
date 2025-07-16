class Solution {
public:
    bool static comp(vector<int> a,vector<int> b){
        return a[1] < b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end(),comp);
        int cnt=0;
        int e=intervals[0][1];
        for(int i=1;i<n;i++){

            if(intervals[i][0] >= e){
               e=intervals[i][1];
            }else{
               cnt++;
            }
        }
        return cnt;
    }
};