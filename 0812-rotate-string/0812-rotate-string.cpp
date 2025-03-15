class Solution {
public:
    
    bool rotateString(string s, string goal) {
        
        if(s.length()!=goal.length())
        return false;

        string temp=s+s;
        int i=0;int j=0;
        while(i<temp.length()){
            cout<<temp[i]<<" "<<goal[j]<<endl;
            if(temp[i]==goal[j]){
                j++;
            }
            else{
                i=i-j;
                j=0;
            }
            if(j>=goal.length()) break;
            i++;
        }
        return j==goal.length();
    }
};