class Solution {
public:
    void solve(string num,vector<string>& ans,string temp,int target,long sum,long prev,int ind){
        if(ind == num.size()){
            if(sum == target){
                ans.push_back(temp);
            }
            return;
        }
        for(int i=ind;i<num.length();i++){
            if(i > ind && num[ind] == '0')break;
            string substr=num.substr(ind,i-ind+1);
            long sub=stol(substr);
            if(ind==0){
                solve(num,ans,temp+substr,target,sub,sub,i+1);
            }else{
                solve(num,ans,temp+'+'+substr,target,sub+sum,sub,i+1);
                solve(num,ans,temp+'-'+substr,target,sum-sub,-sub,i+1);
                solve(num,ans,temp+'*'+substr,target,sum-prev+(prev*sub),prev*sub,i+1);
            }

        }
    }
    vector<string> addOperators(string num, int target) {
          
        int n=num.length();
        vector<string> ans;
        string temp="";
        solve(num,ans,temp,target,0,0,0);
        return ans;
    }
};