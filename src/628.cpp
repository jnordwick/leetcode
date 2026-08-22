class Solution {
public:

    int maximumProduct(vector<int>& nums) {
        int hist[2001] = {};
        int *h = hist + 1000;

        for(auto x : nums) h[x]++;
        int mins[2] = {}, maxs[3] = {};
        int mini = 0, maxi = 0;

        for(int i = -1000; mini < 2;) {
            if(h[i] != 0) mins[mini++]=i, h[i]--;
            else ++i;
        }
        h[mins[0]]++, h[mins[1]]++;
        for(int i = 1000; maxi < 3;) {
            if(h[i] != 0) maxs[maxi++]=i, h[i]--;
            else --i;
        }

        int mx1 = maxs[0] * maxs[1] * maxs[2];
        int mx2 = mins[0] * mins[1] * maxs[0];
        return max(mx1, mx2);
    }
};
