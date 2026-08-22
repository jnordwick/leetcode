#include <immintrin.h>

class Solution {
public:
    int minimumPushes(string word) {
        constexpr int weight[26] = {4,4,3,3,3,3,3,3,3,3,2,2,2,2,2,2,2,2,1,1,1,1,1,1,1,1};
        int hist[26] = {};
        for(auto c : word) hist[c-'a']++;
        sort(begin(hist), end(hist));
        int dot = 0; 
        for(int i = 0; i < 26; ++i)
            dot += weight[i]*hist[i];
        return dot;
    }
};
