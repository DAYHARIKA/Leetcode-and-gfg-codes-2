class Solution {
public:
    
    bool rotateString(string s, string goal) {
        
        if(s.length() == 0)return true;
        if(goal.length() != s.length())return false;
        string news=s+s;
        return news.find(goal)<news.length();
    }
};