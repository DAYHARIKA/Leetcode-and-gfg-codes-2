class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string> mp(wordList.begin(),wordList.end());//checking purpose
        queue<pair<int,string>> q;

        q.push({1,beginWord});
        mp.erase(beginWord);

        while(!q.empty()){
            pair<int,string> temp=q.front();
            q.pop();

            int step=temp.first;
            string str=temp.second;

            for(int i=0;i<str.length();i++){
                char original=str[i];
                for(char ch='a';ch <='z';ch++){
                    str[i]=ch;
                    if(mp.find(str) != mp.end()){
                        if(str == endWord)return step+1;
                        q.push({step+1,str});
                        mp.erase(str);
                    }
                }
                str[i]=original;
            }
        }

        return 0;
    }
};