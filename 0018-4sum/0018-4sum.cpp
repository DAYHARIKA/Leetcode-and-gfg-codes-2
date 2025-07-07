class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        int n=nums.size();
           sort(nums.begin(),nums.end());
           vector<vector<int>> ans;
           for(int i=0;i<n;i++){
               
               if(i>0 && nums[i] == nums[i-1])continue;

               for(int j=i+1;j<n;j++){
                   if(j != (i+1) && nums[j] == nums[j-1])continue;
                   int k1=j+1;
                   int k2=n-1;

                    while(k1<k2){

                        long long sum=nums[i];
                        sum +=nums[j];
                        sum +=nums[k1];
                        sum +=nums[k2];
                        if(sum > target){
                            k2--;
                        }else if(sum < target){
                            k1++;
                        }else{
                            vector<int> temp={nums[i],nums[j],nums[k1],nums[k2]};
                            ans.push_back(temp);
                            k1++;
                            k2--;
                            while(k1<k2 && nums[k1]==nums[k1-1])k1++;
                            while(k1<k2 && nums[k2]==nums[k2+1])k2--;
                        }

                    }
               }

           }
           return ans;
    }
};