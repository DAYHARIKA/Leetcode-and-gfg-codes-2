class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        queue<pair<int,string>> q;
        unordered_set<string> st(wordList.begin(),wordList.end());
        q.push({1,beginWord});
        st.erase(beginWord);

        while(!q.empty()){
            pair<int,string> req=q.front();
            q.pop();

            string str=req.second;
            int step=req.first;
            // if(str == endWord)return step+1;
            for(int i=0;i<str.length();i++){
                char original=str[i];
                for(char k='a';k<='z';k++){
                    str[i]=k;
                    if(st.find(str) != st.end()){
                        if(str == endWord)return step+1;
                        q.push({step+1,str});
                        st.erase(str);
                    }
                }
                str[i]=original;
            }
        }

        return 0;

    }
};