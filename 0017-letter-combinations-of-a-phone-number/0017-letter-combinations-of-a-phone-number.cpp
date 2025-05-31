class Solution {
public:
    void solve(string digits,vector<string> mapping,vector<string>& ans,string temp,int ind){
         if(ind == digits.size()){
            ans.push_back(temp);
            return;
         }
         int num=digits[ind]-'0';
         string val=mapping[num];
         for(int i=0;i<val.size();i++){
            temp.push_back(val[i]);
            solve(digits,mapping,ans,temp,ind+1);
            temp.pop_back();
         }
    }

    vector<string> letterCombinations(string digits) {
        
        vector<string> ans;
        if(digits.size() == 0)return ans;
        vector<string> mapping={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        solve(digits,mapping,ans,"",0);
        return ans;
    }
};