class Solution {
public:
    string removeKdigits(string num, int k) {
           
        string res = "";
        for (int i = 0; i < num.size(); i++) {
            while (!res.empty() && k > 0 && res.back()-'0' > num[i]-'0') {
                res.pop_back();
                k--;
            }
            if (!res.empty() || num[i] != '0') {
                res.push_back(num[i]);
            }
        }
        while (k > 0 && !res.empty()) {
            res.pop_back();
            k--;
        }
        return res.empty() ? "0" : res;
    }
};