class Solution {
public:
    int findGCD(vector<int>& n) {
        return gcd(ranges::min(n), ranges::max(n));
    }
};
