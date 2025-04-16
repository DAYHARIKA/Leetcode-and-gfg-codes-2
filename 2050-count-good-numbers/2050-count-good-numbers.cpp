class Solution {
public:
    int M=1e9 + 7;
    long long power(long long a,long long b){
        if(b == 0)return 1;
        long long t=power(a,b/2);
        t=(t*t)%M;
        if(b%2 == 1)return (t*a)%M;
        return t;
    }
    int countGoodNumbers(long long n) {
        
        long long even=(n+1)/2;
        long long odd=n/2;
        long long ans=(power(5,even)*power(4,odd))%M;
        return (int)ans;
    }
};