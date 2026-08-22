class Solution {
public:
    int dprod(int x) {
        int p = 1;
        while (x > 0) {
            p *= x % 10;
            x /= 10;
        }
        return p;
    }

    int smallestNumber(int n, int t) {
        auto [P, D] = div(n, 10);

        int pref = dprod(P);
        int g = gcd(pref, t);
        int m = t / g;

        int ld = ((D + m - 1) / m) * m;

        return n - D + min(10, ld);
    }
};
