class Solution {
public:
    void merge(vector<pair<int,int>> &numsarr,vector<int> &ans,int low,int mid,int high){
         vector<pair<int,int>> temp;
         int left=low;
         int right=mid+1;
         while(left <= mid && right <= high){
            if(numsarr[left].first > numsarr[right].first){
               ans[numsarr[left].second] += high-right+1;
               temp.push_back(numsarr[left]);
               left++;
            }else{
                temp.push_back(numsarr[right]);
                right++;
            }
         }
         while(left <= mid){
            temp.push_back(numsarr[left]);
               left++;
         }
         while(right <= high){
            temp.push_back(numsarr[right]);
                right++;
         }
         for(int i=low;i<=high;i++){
            numsarr[i]=temp[i-low];
         }
    }
    void mergesort(vector<pair<int,int>> &numsarr,vector<int> &ans,int low,int high){
         if(low < high){
            int mid=(low+high)/2;
            mergesort(numsarr,ans,low,mid);
            mergesort(numsarr,ans,mid+1,high);
            merge(numsarr,ans,low,mid,high);
         }
    }
    vector<int> countSmaller(vector<int>& nums) {
        
        int n=nums.size();
        vector<pair<int,int>> numsarr;
        for(int i=0;i<n;i++){
            numsarr.push_back({nums[i],i});
        }
        vector<int> ans(n);
        mergesort(numsarr,ans,0,n-1);
        return ans;
    }
};