class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if(words.empty() || s.empty())return result;

        int wordlen=words[0].size();
        int wordcount=words.size();
        int totallen=wordlen*wordcount;
        int n=s.size();
        if(n < totallen)return result;

        unordered_map<string,int> need;
        need.reserve(wordcount*2);
        for(auto &w:words)need[w]++;

        for(int offset=0;offset < wordlen;offset++){
            unordered_map<string,int> seen;
            seen.reserve(wordcount*2);
            int left=offset;
            int matched=0;

            for(int j=offset;j+wordlen <= n;j += wordlen){
                string word=s.substr(j,wordlen);
                if(need.find(word) != need.end()){
                    seen[word]++;
                    if(seen[word] <= need[word]){
                        matched++;
                    }else{
                        while(seen[word] > need[word]){
                            string leftword=s.substr(left,wordlen);
                            seen[leftword]--;
                            if(seen[leftword] < need[leftword]){
                                matched--;
                            }
                            left += wordlen;
                        }
                    }

                    if(matched == wordcount){
                        result.push_back(left);
                        string leftword=s.substr(left,wordlen);
                        seen[leftword]--;
                        matched--;
                        left += wordlen;
                    }
                }else{
                    seen.clear();
                    matched=0;
                    left=j+wordlen;
                }
            }
        }
        return result;
    }
};