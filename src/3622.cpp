class Solution {
public:
    bool checkDivisibility(int n) {
        return ![&](this auto t, int x, int s, int p) -> bool {
            return x ? t(x/10, s+(x%10), p*(x%10)) : n%(s+p);
        }(n,0,1);
    }
};

