class Solution {
public:
    string getPermutation(int n, int k) {
        k--;
        string result="";
        vector<int> nums(n);
        iota(nums.begin(),nums.end(),1);
        vector<int> factorials(n);
        factorials[0]=1;
        for(int i=1;i<n;i++){
            factorials[i]=factorials[i-1]*i;
        }
        for(int i=n-1;i>=0;i--){
            int idx=k/factorials[i];
            result += to_string(nums[idx]);
            nums.erase(nums.begin()+idx);
            k %= factorials[i];
        }
        return result;
    }
};