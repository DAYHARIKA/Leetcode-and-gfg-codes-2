class Solution {
public:
    int possible(vector<int>& arr,int n,int max_pages){
    int student=1;
    int cnt_pages=0;
    for(int i=0;i<n;i++){
        if(cnt_pages+arr[i] <= max_pages){
            cnt_pages += arr[i];
        }else{
            student++;
            cnt_pages=arr[i];
        }
    }
    return student;
    }
    int splitArray(vector<int>& arr, int m) {
        int n=arr.size();
        if (m > n) return -1;
        int ans=-1;
        int low=*max_element(arr.begin(),arr.end());
        int high=accumulate(arr.begin(),arr.end(),0);
        while(low <= high){
            int mid=(low+high)/2;
            int poss=possible(arr,n,mid);
            if(poss <= m){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};