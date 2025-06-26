class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int size=s.length();
        int block[256]={0};
        int pointer1=0;
        int pointer2=0;
        int largestlength=0;
        while(pointer2 < size){  
            block[s[pointer2]]++;
            while(block[s[pointer2]] > 1){
                block[s[pointer1]]--;
                pointer1++;
            }
            largestlength=max(largestlength,pointer2-pointer1+1);
            pointer2++;
        }
        return largestlength;

    }
};