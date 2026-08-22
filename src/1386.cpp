static consteval auto make_taken_table() {
    std::array<uint8_t, 256> t{};
    
    constexpr uint8_t l = 0x0f;
    constexpr uint8_t m = 0x3c;
    constexpr uint8_t r = 0xf0;

    for (int x = 0; x < 256; ++x) {
        bool ll = !(x & l);
        bool mm = !(x & m);
        bool rr = !(x & r);

        t[x] = 2 - ((ll & rr) ? 2 : (ll || mm || rr));
    }

    return t;
}

static constexpr auto taken = make_taken_table();

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& s) {
        unordered_map<int, uint8_t> chart;
        chart.reserve(min(n,(int)s.size()));
        for(auto const &x : s) {
            if(uint32_t xx = (1 << x[1]) & 0b1111111100; xx)
                chart[x[0]] |= xx >> 2;
        }
        int c = 0, i = 0;
        for(auto const &[_, x] : chart) c += taken[x];
        return n*2 - c;
    } 
};
