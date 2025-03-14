class Solution {
public:
    int findingMinimum(vector<string>& strs){
        int mini=INT_MAX;
        for(int i=0;i<strs.size();i++){
            int temp=strs[i].length();
            mini=min(mini,temp);       
        }
        return mini;
    }
    string longestCommonPrefix(vector<string>& strs) {
        
        int n=strs.size();
        string longestPrefix="";
        int mini=findingMinimum(strs);
        for(int i=0;i<mini;i++){
               char ch=strs[0][i];
               int flag=0;
            for(int j=1;j<n;j++){
                if(strs[j][i] != ch){
                    flag=1;
                    break;
                }
            }
            if(flag == 0){
                longestPrefix += ch;
            }else{
                break;
            }
        }
        return longestPrefix;
    }
};