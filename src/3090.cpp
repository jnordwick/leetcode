class Solution {
public:
    int maximumLengthSubstring(string s) {
        int hist[26] = {};
        int lhs = 0, mx = 0;
        for(int rhs = 0; rhs < s.size(); ++rhs) {
            hist[s[rhs]-'a']++;
            while(hist[s[rhs]-'a'] == 3)
                hist[s[lhs++]-'a']--;
            mx = max(mx, rhs-lhs+1);
        }
        return mx;
    }
};
