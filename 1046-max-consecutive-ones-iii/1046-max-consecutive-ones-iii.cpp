class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int zeros=0;
        int point1=0;
        int point2=0;
        int maxlen=0;
        while(point2 < n){

            if(nums[point2] == 0){
                zeros++;
            }
            while(zeros > k){
                if(nums[point1] == 0){
                    zeros--;
                }
                point1++;
            }
            maxlen=max(maxlen,point2-point1+1);
            point2++;
        }
        return maxlen;
    }
};