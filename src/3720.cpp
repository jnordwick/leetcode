class Solution {
public:

    bool try_fail_high(string const &t, string &r, uint *hist, uint i) {
        uint j = t[i];
        while(j <= 'z'&& hist[j] == 0) ++j;
        if(j > 'z') return false;
        r[i++] = j;
        hist[j]--;
        for(j = 'a'; j <= 'z'; ++j) {
            for(int k = 0; k < hist[j]; ++k) r[i++] = j;
        }
        return true;
    }

    void fail_low(string const &t, string &r, uint *hist, uint i) {
        uint c = t[i];
        for(; i < r.size(); ++i) {
            while(hist[c] == 0) c--;
            r[i] = c;
            hist[c]--;
        }
    }

    string lexGreaterPermutation(string const &s, string const &t) {
        uint hist[256] = {}, n = s.size();
        for(auto x : s) hist[x]++;
        string r(n, ' ');
        for(uint i = 0; i < n; ++i) {
            if(hist[t[i]] == 0) {
                if(try_fail_high(t, r, hist, i)) return r;
                fail_low(t, r, hist, i);
                break;
            }
            hist[t[i]]--;
            r[i] = t[i];
        }
        if(!next_permutation(r.begin(), r.end()))
            return "";
        return r;
    }
};
