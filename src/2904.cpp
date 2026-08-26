class Solution {
public:
    string shortestBeautifulSubstring(string const &s, int k) {
        uint l=0, r, c=0, n=s.size();
        while(l < n && s[l] == '0') l++;
        r = l;
        while(r < n && c < k)
            c += s[r++] == '1';
        if(c < k) return "";
        string_view best = string_view(s).substr(l, r-l);
        for(; r < n; ++r) {
            if(s[r] == '1') {
                while(s[++l] == '0') ;
                if(r - l < best.size()) {
                    string_view cand = string_view(s).substr(l, r-l+1);
                    if(cand.size() < best.size() || cand < best) best = cand;
                }
            }
        }
        return string(best);
    }
};
