class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int res[3] = {};
        for(auto x : stones) res[x%3]++;
        return ~res[0]%2 ? min(res[1], res[2]) > 0 : abs(res[1] - res[2]) > 2;
    }
};
