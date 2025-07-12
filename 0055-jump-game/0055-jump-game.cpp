class Solution {
public:
    bool canJump(vector<int>& nums) {
         
         int maxind=0;
         for(int i=0;i<nums.size();i++){
            
             if(i+nums[i] > maxind){
                maxind=i+nums[i];
             }

             if(maxind == i && i != nums.size()-1){
                return false;
             }
         }
         return true;
    }
};