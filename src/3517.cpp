class Solution {
public:
    string smallestPalindrome(string s) {
        int hist[26] = {};
        for(uint i = 0; i < s.size()/2; ++i)
            hist[s[i] - 'a']++;

        uint t = 0;
        for(uint i = 0; i < 26; ++i) {
            for(uint x = 0; x < hist[i]; ++x)
                s[t+x] = i+'a';
            t += hist[i];
        }

        uint n = s.size() - 1;
        for(uint i = 0; i < s.size() / 2; ++i)
            s[n - i] = s[i];

        return s;
    }
};
