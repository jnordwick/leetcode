class Solution {
public:
    int minimumPushes(string const &word) {
        uint n = word.size();
        uint q = n >> 3, r = n & 7;
        return (q + 1) * (4 * q + r);
    }
};
