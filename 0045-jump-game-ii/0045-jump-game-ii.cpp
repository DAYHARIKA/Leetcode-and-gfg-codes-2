class Solution {
public:
    int jump(vector<int>& nums) {

        int n=nums.size();
        int maxind=0;
        int cnt=0;
        int lastpos=0;
        for(int i=0;i<n-1;i++){
            maxind=max(maxind,i+nums[i]);
            if(lastpos == i ){
                lastpos=maxind;
                cnt++;
                if(lastpos >= n-1)break;
            }
        }
        return cnt;
    }
};