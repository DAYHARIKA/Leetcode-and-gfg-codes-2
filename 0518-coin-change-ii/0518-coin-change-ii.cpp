class Solution {
public:
    int m=(int)1e9+7;
    int change(int amount, vector<int>& coins) {
        
        vector<unsigned int> dp(amount+1,0);

        for(int i=0;i<=amount;i++){
            if(i%coins[0] == 0)dp[i]=1;
        }

        for(int ind=1;ind<coins.size();ind++){
            for(int tar=0;tar<=amount;tar++){
                
                unsigned int np=dp[tar];
                unsigned int p=0;
                if(coins[ind] <= tar){
                    p=dp[tar-coins[ind]];
                }

                dp[tar]=(np+p);
            }  
        }

        return (int)dp[amount];
    }
};