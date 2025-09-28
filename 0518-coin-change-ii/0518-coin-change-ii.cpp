class Solution {
public:
    int change(int value, vector<int>& d) {
        vector<unsigned long long> prev(value + 1, 0);
        prev[0] = 1;

        for (int c:d) {
            for (int j = c; j <= value; j++) {
                prev[j]+=prev[j - c];
            }
        }
        return prev[value];
    }
};
