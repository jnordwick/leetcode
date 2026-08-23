class Solution {
public:
    pair<int,int> sumcnt(string_view sv) {
        int s = 0, c = 0;
        for(auto x : sv) {
            if(x == '?') c++;
            else s += x - '0';
        }
        return make_pair(s, c);
    }

    bool sumGame(string const &m) {
        auto [lsum, lcnt] = sumcnt(string_view(m).substr(0, m.size()/2));
        auto [rsum, rcnt] = sumcnt(string_view(m).substr(m.size()/2));
        return (lcnt + rcnt) & 1 || (rsum - lsum) != 9 * (lcnt - rcnt) / 2;
    }
};
