class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n=asteroids.size();
        vector<int> ans;
        stack<int> s;
        int i=n-1;
        while(i>=0){
            int flag=0;

            while(!s.empty() && s.top() < 0 && asteroids[i] > 0){
                 if(abs(s.top()) > abs(asteroids[i])){
                    flag=1;
                    break;
                 }else if(abs(s.top()) < abs(asteroids[i])){
                    s.pop();
                 }else{
                    flag=1;
                    s.pop();
                    break;
                 }
            }
            if(flag == 0){
                s.push(asteroids[i]);
            }
            i--;
        }
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};