class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n=hand.size();
        if(n%groupSize != 0)return false;
        
        map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[hand[i]]++;
        }

        for(auto it:mp){
            int ele=it.first;
            int freq=it.second;
            if(freq == 0)continue;
            while(freq--){
                for(int i=ele;i<ele+groupSize;i++){
                    if(mp[i] == 0)return false;
                    mp[i]--;
                }
            }
        }
        return true;
    }
};