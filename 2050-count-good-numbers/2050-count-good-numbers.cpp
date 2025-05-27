class Solution {
public:
    int M=1e9 + 7;
    long long power(long long a,long long b){
        long long res=1;
        while(b != 0){
            if(b%2 == 1){
               res = (res*a)%M;
            }
            a=(a*a)%M;
            b=b/2;
        }
        return res;

    }
    int countGoodNumbers(long long n) {
        
        long long even=(n+1)/2;
        long long odd=n/2;
        long long ans=(power(5,even)*power(4,odd))%M;
        return (int)ans;
    }
};