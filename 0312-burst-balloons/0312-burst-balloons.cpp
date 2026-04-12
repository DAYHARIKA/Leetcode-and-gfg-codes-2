class Solution {
public:
    int solve(vector<int>& nums,int i,int j){

        if(i>j)return 0;
        int maxi=INT_MIN;
        for(int ind=i;ind<=j;ind++){
            
            int cost=(nums[i-1]*nums[ind]*nums[j+1])+solve(nums,i,ind-1)+solve(nums,ind+1,j);
            maxi=max(maxi,cost);
        }

        return maxi;
    }
    int maxCoins(vector<int>& nums) {
        
        int c=nums.size();

        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        int m=nums.size();

        vector<vector<int>> dp(m,vector<int>(m,0));


        for(int i=c;i>=1;i--){
            for(int j=1;j<=c;j++){
                if(i>j)continue;
                int maxi=INT_MIN;
                for(int ind=i;ind<=j;ind++){
                    
                    int cost=(nums[i-1]*nums[ind]*nums[j+1])+dp[i][ind-1]+dp[ind+1][j];
                    maxi=max(maxi,cost);
                }

                dp[i][j]=maxi;
            }
        }

        return dp[1][c];
    }
};