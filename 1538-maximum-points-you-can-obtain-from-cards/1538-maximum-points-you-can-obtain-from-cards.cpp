class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        if(n < k)return 0;
        int sum=0;
        int maxsum=INT_MIN;

        for(int i=0;i<k;i++){
            sum += cardPoints[i];
        }

        maxsum=sum;
        int l=n-1;
        for(int i=k-1;i>=0;i--){
            sum = sum-cardPoints[i];
            sum = sum+cardPoints[l];
            l--;
            maxsum=max(maxsum,sum);
        }

        return maxsum;
    }
};