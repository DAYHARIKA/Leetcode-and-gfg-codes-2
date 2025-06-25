class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int leftsum=0;
        int rightsum=0;
        for(int i=0;i<k;i++){
            leftsum += cardPoints[i];
        }
        int maxsum=leftsum;
        int j=n-1;
        for(int i=k-1;i>=0;i--){
            leftsum =leftsum-cardPoints[i];
            rightsum += cardPoints[j];
            maxsum=max(maxsum,leftsum+rightsum);
            j--;
        }
        return maxsum;
    }
};