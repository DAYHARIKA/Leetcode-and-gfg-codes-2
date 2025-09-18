class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> numbers;
        for(int i=1;i <= n;i++){
            numbers.push_back(i);
        }
        k--;
        string result="";
        int fact=1;
        for(int i=1;i<n;i++){
            fact *= i;
        }
        for(int i=n;i>0;i--){
            int index=k/fact;
            result += to_string(numbers[index]);
            numbers.erase(numbers.begin()+index);
            if(i>1){
                k %= fact;
                fact /=(i-1);
            }
        }
        return result;
    }
};