class Solution {
public:
    vector<int> buf;

    int count(span<int> s, span<int> t) {
        int cnt = 0, si = 0;
        for(int ti = 0; ti < t.size(); ++ti) {
            while(si < s.size()
                && s[si] <= 2*static_cast<int64_t>(t[ti]))
              si++;
            cnt += s.size() - si;
            if(si == s.size()) break;
        }
        return cnt;
    }

    int rec(span<int> v) {
        if(v.size() == 1) return 0;

        int half = v.size() / 2;
        span<int> lhs = v.first(half);
        span<int> rhs = v.last(v.size() - half);
        int cntl = rec(lhs);
        int cntr = rec(rhs);

        int cntx = count(lhs, rhs);

        buf.resize(v.size());
        int p1 = 0, p2 = 0;
        for (int i = 0; i < v.size(); ++i) {
            if (p1 == lhs.size()) {
                buf[i] = rhs[p2++];
            } else if (p2 == rhs.size()) {
                buf[i] = lhs[p1++];
            } else if (lhs[p1] < rhs[p2]) {
                buf[i] = lhs[p1++];
            } else {
                buf[i] = rhs[p2++];
            }
        }

        copy(buf.begin(), buf.end(), v.begin());
        return cntl + cntr + cntx;
    }

    int reversePairs(vector<int> &nums) {
        buf.resize(nums.size());
        int cnt = rec(span(nums));
        return cnt;
    }

};
