class Solution {
public:
    int cnt_pairs(vector<int> &nums, int low, int mid, int high) {
        int cnt = 0;
        int right = mid + 1;

        for (int left = low; left <= mid; left++) {
            while (right <= high && nums[left] > 2LL * nums[right]) {
                right++;
            }
            cnt += (right - (mid + 1));
        }

        return cnt;
    }
    void merge(vector<int> &nums,int low,int mid,int high){
        
        vector<int> temp;
        int left = low, right = mid + 1;

        while (left <= mid && right <= high) {
            if (nums[left] <= nums[right]) {
                temp.push_back(nums[left++]);
            } else {
                temp.push_back(nums[right++]);
            }
        }

        while (left <= mid) temp.push_back(nums[left++]);
        while (right <= high) temp.push_back(nums[right++]);

        for (int i = low; i <= high; i++) {
            nums[i] = temp[i - low];
        }
        
        
    }
    int mergesort(vector<int> &nums,int low,int high){
        int cnt=0;
        if(low >= high){
            return 0;
        }
            
        int mid=(low+high)/2;
        
        cnt += mergesort(nums,low,mid);
        cnt += mergesort(nums,mid+1,high);
        cnt += cnt_pairs(nums,low,mid,high);
        merge(nums,low,mid,high);
        return cnt;
    }
    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        int ans=mergesort(nums,0,n-1);
        return ans;
    }
};