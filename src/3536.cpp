class Solution {
public:

    int maxProduct(int n) {
        uint64_t hist = 0;
        for (; n; n /= 10)
            hist += (1ULL << ((n % 10) << 2));

        int high = (63 - __builtin_clzll(hist)) >> 2;
        hist -= (1ULL << (high << 2));
        int low = (63 - __builtin_clzll(hist)) >> 2;

        return high * low;     
    }
};
