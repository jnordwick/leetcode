class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        bool hist[101] = {};
        for(auto n : nums) hist[n] = true;

        vector<int> m;
        int p = 1, e = 100;
        while(!hist[p]) p++;
        while(!hist[e]) e--;
        for( ; p <= e; ++p)
            if(!hist[p]) m.push_back(p);
        return m;
    }
};
