class Solution {
public:
    int beautySum(string s) {
        int n=s.length();
        int sum=0;
        for(int i=0;i<n;i++){
            int arr[26]={0};
            for(int j=i;j<n;j++){
                arr[s[j]-'a']++;
                int maxi=INT_MIN;
                int mini=INT_MAX;
                for(int i=0;i<26;i++){
                    if(arr[i] > 0){
                        maxi=max(maxi,arr[i]);
                        mini=min(mini,arr[i]);
                    }
                }
                sum += (maxi-mini);
            }
        }
        return sum;
    }
};