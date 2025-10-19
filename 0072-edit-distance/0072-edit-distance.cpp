class Solution {
private:
    int solve(string word1, string word2, int i, int j){
        
        if(j == 0)return i;
        if(i == 0)return j;

        if(word1[i-1] == word2[j-1]){
           return solve(word1,word2,i-1,j-1);
        }
        int insert=solve(word1,word2,i,j-1);
        int dele=solve(word1,word2,i-1,j);
        int replace=solve(word1,word2,i-1,j-1);

        return 1+min({insert,dele,replace});
    }
public:
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();

        vector<int> prev(m+1,0);
        vector<int> curr(m+1,0);

        for(int j=0;j<=m;j++)prev[j]=j;

        for(int i=1;i<=n;i++){
            curr[0]=i;
            for(int j=1;j<=m;j++){

                if(word1[i-1] == word2[j-1]){
                   curr[j]=prev[j-1];
                }else{
                    int insert=curr[j-1];
                    int dele=prev[j];
                    int replace=prev[j-1];

                    curr[j]=1+min({insert,dele,replace});
                }
                
            }
            prev=curr;
        }

        return prev[m];

    }
};