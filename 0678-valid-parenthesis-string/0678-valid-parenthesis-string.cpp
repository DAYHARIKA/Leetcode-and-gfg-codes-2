class Solution {
public:
    bool checkValidString(string s) {
         
         int n=s.length();
         int mini=0;
         int maxi=0;
         for(int i=0;i<n;i++){

            if(s[i] == '('){
               mini = mini + 1;
               maxi = maxi +1;
            }

            if(s[i] == ')'){
                mini=mini-1;
                maxi=maxi-1;
            }

            if(s[i] == '*'){
                mini=mini-1;
                maxi=maxi+1;
            }

            if(maxi < 0)return false;
            if(mini < 0)mini=0;
         }

         if(mini == 0)return true;
         return false;
    }
};