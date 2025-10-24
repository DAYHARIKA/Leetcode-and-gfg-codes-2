class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int n=nums.size(); 
        int cnt=0;  
        int ele;  
        for(int i=0;i<n;i++){

            if(cnt == 0){
                cnt++;
                ele=nums[i];
            }else if(nums[i] == ele){
                cnt++;
            }else{
                cnt--;
            }
        }
        cnt=0;
        for(int i=0;i<n;i++){
            if(nums[i]  == ele)cnt++;
        }
        if(cnt > n/2)return ele;
        else return -1;
    }
};