class Solution {
public:
    int maxele(vector<int>& piles){
        int maxi=INT_MIN;
        for(int i=0;i<piles.size();i++){
            maxi=max(maxi,piles[i]);
        }
        return maxi;
    }
    long long func(vector<int>& piles,int t){

        long long total_time=0;
        for(int i=0;i<piles.size();i++){

            total_time += ceil(piles[i] / (double)t);
        }
        return total_time;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int l=1;
        int hi=maxele(piles);

        while(l<=hi){
            int mid=l + (hi - l) / 2;
            long long time=func(piles,mid);

            if(time <= h){
                hi=mid-1;
            }else{
                l=mid+1;
            }

        }
        return l;
    }
};