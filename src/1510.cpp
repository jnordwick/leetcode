class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool> dp(n+1);
        for(int r = 1; r <= n; ++r) {
            for(int i = 1; i*i <= r; ++i) {
                if(!dp[r-i*i]) {
                    dp[r] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};
