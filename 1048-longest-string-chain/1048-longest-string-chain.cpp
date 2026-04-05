class Solution {
public:
    static bool comp(string &a,string &b){
         return a.length()<b.length();
    }
    bool check(string word,string prede){
         
         int n=word.length();
         int m=prede.length();
         
         if(n != m+1)return false;

         int i=0;
         int j=0;

         while(i<n && j<m){

            if(word[i] == prede[j]){
                i=i+1;
                j=j+1;
            }else{
                i=i+1;
            }
         }

         return j==m;

    }
    int solve(vector<string>& words,int n){

        vector<int> dp(n,1);
        int maxi=0;

        for(int i=0;i<n;i++){
            for(int j=i-1;j>=0;j--){

                if(check(words[i],words[j])){
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
            maxi=max(maxi,dp[i]);
        }
        return maxi;
    }
    int longestStrChain(vector<string>& words) {
        
        int n=words.size();

        sort(words.begin(),words.end(),comp);

        return solve(words,n);
    }
};