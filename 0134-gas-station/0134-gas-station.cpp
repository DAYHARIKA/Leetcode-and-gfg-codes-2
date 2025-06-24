class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int start=0;
        int sum=0;
        int gasintake=0;
        for(int i=0;i<cost.size();i++){
            gasintake += gas[i]-cost[i];
            sum += gas[i]-cost[i];
            if(gasintake < 0){
               start=i+1;
               gasintake=0;
            }
        }
        return sum>=0?start:-1;
    }
};