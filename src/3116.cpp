vector<int64_t> build(span<int> cs) {
    vector<int64_t> f(1 << cs.size());
    f[0] = 1;
    for(uint m = 1; m < (1 << cs.size()); ++m) {
        uint top = bit_width(m) - 1;
        uint sub = m ^ (1 << top);
        f[m] = ((popcount(m)&1) ? 1 : -1) * lcm(cs[top], f[sub]);
    }
    return f;
}

int64_t rnk(vector<int64_t> const &f, int64_t v) {
    int64_t sum = 0;
    for(uint i = 1; i < f.size(); ++i)
        sum += v / f[i];
    return sum;
}
 
class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        vector<int64_t> cc = build(coins);

        int64_t lo = 0, hi = 1 + k * (int64_t)*ranges::min_element(coins);
        while(lo < hi) {
            int64_t mid = (lo + hi) / 2;
            int64_t mid_r = rnk(cc, mid);
            if(mid_r >= k) hi = mid;
            else lo = mid + 1;
        }

        return lo;
    }
};
