class Solution {
public:
    int lower_bou(vector<int>& arr, int x){

        int n=arr.size();
        int low=0;
        int high=n-1;
        int ans=n;
        while(low <= high){
            int mid=low+(high-low)/2;
            if(arr[mid] >= x){
                
                high=mid-1;
                ans=mid;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
    int upper_bou(vector<int>& arr, int x){

        int n=arr.size();
        int low=0;
        int high=n-1;
        int ans=n;
        while(low <= high){
            int mid=low+(high-low)/2;
            if(arr[mid] > x){
                
                high=mid-1;
                ans=mid;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        
         int lb=lower_bou(nums,target);
         int ub=upper_bou(nums,target);

         vector<int> ans={-1,-1};
         if(lb == ub){
            return ans;
         }else{
            return {lb,ub-1};
         }

    }
};