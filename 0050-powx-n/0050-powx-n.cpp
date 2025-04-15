class Solution {
public:
    double myPow(double x, int n) {
    long long N = n;  // use long long to safely handle INT_MIN

    if (N < 0) {
        x = 1 / x;
        N = -N;
    }

    if (N == 0) return 1;

    double t = myPow(x, N / 2);
    if (N % 2 == 0) {
        return t * t;
    } else {
        return x * t * t;
    }
}

};