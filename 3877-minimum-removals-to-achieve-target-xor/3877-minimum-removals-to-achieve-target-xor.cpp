class Solution {
public:
    int solve(vector<int> &nums,int target,int ind,int sum){

        if(ind < 0){
            if(sum == target) return 0;
            return -1e9;
        }

        int np=solve(nums,target,ind-1,sum);
        int p=1+solve(nums,target,ind-1,sum^nums[ind]);
        
        return max(np,p);
    }
    
    int minRemovals(vector<int>& nums, int target) {
        
        int n=nums.size();
        //int ans=solve(nums,target,n-1,0);

        unordered_map<int,int> prev;
        prev[0]=0;

        for(int i=1;i<=n;i++){
            
            unordered_map<int,int> curr;
            //notpick
            curr=prev;
            //pick
            int x=nums[i-1];
            for(auto &[xr, len]:prev){
                
                int nxor=xr^x;
                curr[nxor]=max(curr[nxor],len+1);
                
            }
            prev=curr;

        }


        if(prev.find(target) == prev.end())return -1;
        return n-prev[target];
        
    }
};