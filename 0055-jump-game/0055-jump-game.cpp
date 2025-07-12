class Solution {
public:
    bool canJump(vector<int>& nums) {
         
         int maxind=0;
         for(int i=0;i<nums.size();i++){
            
             if(i+nums[i] > maxind){
                maxind=i+nums[i];
             }
             if(maxind >= nums.size()-1)break;
             if(maxind == i ){
                return false;
             }
         }
         return true;
    }
};