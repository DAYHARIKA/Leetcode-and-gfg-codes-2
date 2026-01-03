class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int ue=0;
        int mful=INT_MAX;
        int rt=0;
        int i=0;
        while(i<gas.size()){
            ue += gas[i]-cost[i];
            if(ue < mful){
                mful=ue;
                rt = i+1;
            }
            i++;
        }
        if(ue < 0)return -1;
        return rt%gas.size();
    }
};