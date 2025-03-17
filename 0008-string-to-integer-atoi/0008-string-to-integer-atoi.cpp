class Solution {
public:
    int myAtoi(string s) {
        
        int n=s.length();
        double num=0;
        int i=0;
        while(s[i] == ' '){
            i++;
        }
        bool positive=(s[i]=='+');
        bool negative=(s[i]=='-');
        (positive==true)?i++:i;
        (negative==true)?i++:i;
        while(i<n && s[i] >= '0' && s[i] <= '9'){
            num=num*10+(s[i]-'0');
            i++;
        }
        num=negative?-num:num;
        num=(num>INT_MAX)?INT_MAX:num;
        num=(num<INT_MIN)?INT_MIN:num;
        return num;

    }
};