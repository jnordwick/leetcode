class Solution {
public:
    int stoneGameVIII(vector<int>& v) {
        vector<int> s(v.size());

        // plus over
        s[0] = v[0];
        for(uint i = 1; i < v.size(); ++i)
            s[i] = v[i] + s[i-1];

        // find largest region
        int r = s.back();
        for (uint i = s.size() - 2; i >= 1; --i)
            r = max(r, s[i] - r);
        return r;
    }
};

