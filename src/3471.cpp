class Solution {
public:
    constexpr int singular(vector<int> const &v) {
        int cnt[51] = {};
        for(auto x : v) cnt[x]++;
        for(int i = 50; i > 0; --i) {
            if(cnt[i] == 1) return i;
        }
        return -1;
    }

    constexpr int window(vector<int> const &v) {
        if(v.front() == v.back()) return -1;
        auto [a,b] = minmax(v.front(), v.back());
        bool p[51] = {};
        for(int i = 1; i <= v.size()-2; ++i) p[v[i]] = true;
        return p[b] ? p[a] ? -1 : a : b;
    }

    int largestInteger(vector<int>& nums, int k) {
        if(k == 1) return singular(nums);
        if(k >= nums.size()) return *ranges::max_element(nums);
        return window(nums);
    }
};
