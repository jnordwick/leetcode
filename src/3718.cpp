class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        bool f[102] = {};
        for(auto x : nums)
            if(x <= 100*k && x%k == 0) f[x/k] = true;
        for(uint i = 1; i < 102; ++i) {
            if(!f[i]) return k*i;
        }
        return 0;
    }
};
