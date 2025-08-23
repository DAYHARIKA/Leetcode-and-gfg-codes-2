class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
         
        int N=tasks.size();
        vector<int> arr(26,0);

        for(int i=0;i<N;i++){
            arr[tasks[i]-'A']++;
        }

        sort(arr.begin(),arr.end());

        int maxfreq=arr[25]-1;
        int ideal=maxfreq*n;

        for(int i=24;i>=0;i--){
            ideal -= min(maxfreq,arr[i]);
        }

        if(ideal >= 0)return ideal+N;

        return N;
    }
};