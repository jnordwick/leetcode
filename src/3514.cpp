class Solution {
public:
    
    void fwht(int64_t *f, unsigned N)  {
        for(unsigned stride = 1; stride < N; stride <<= 1) {
            for(unsigned i = 0; i < N; i += 2*stride) {
                for(unsigned j = i; j < i + stride; ++j) {
                    int x = f[j], y = f[j+stride];                    
                    f[j] = x + y, f[j+stride] = x - y;
                }
            }
        }
    }

    int uniqueXorTriplets(vector<int>& nums) {
        constexpr unsigned N = 2048;
        int64_t f[N] = {};

        int max_mask = 1 << bit_width(static_cast<unsigned>(ranges::max(nums)));
        for(auto x : nums) f[x] = 1;
        fwht(f, max_mask);
        for(unsigned i = 0; i < N; ++i) f[i] = f[i] * f[i] * f[i];
        fwht(f, max_mask);
        int cnt = count_if(f, f+max_mask, [](auto x){return x != 0;});
        return cnt;

    }

    int uniqueXorTriplets2(vector<int>& nums) {
        constexpr unsigned N = 2048;
        bool pairs[N] = {}, trips[N] = {};

        for(unsigned i = 0; i < nums.size(); ++i) {
            for(unsigned j = i; j < nums.size(); ++j) {
                int p = nums[i] ^ nums[j];
                pairs[p] = true;
            }
        }

        for(unsigned i = 0; i < nums.size(); ++i) {
            for(unsigned j = 0; j < N; ++j) {
                if(pairs[j]) {
                    int t = nums[i] ^ j;
                    trips[t] = true;
                }
            }
        }
        return count(trips, trips+N, true);
    }
};
