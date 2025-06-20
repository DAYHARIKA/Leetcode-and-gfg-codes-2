class Solution {
public:
    string removeKdigits(string num, int k) {
           
        int n=num.length();
        string res="";
        for(int i=0;i<n;i++){

            while(res.length() != 0 && k > 0 && res.back()-'0' > num[i]-'0'){
                res.pop_back();
                k--;
            }

            if(res.length() != 0 || num[i] != '0'){
                res.push_back(num[i]);
            }
        }

        while(k > 0 && res.size() != 0){
            res.pop_back();
            k--;
        }
        
        if(res.length() == 0)return "0";
        return res;

    }
};