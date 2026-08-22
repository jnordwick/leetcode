class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> cnt {{nums[0], 1}};
        int mx = 1, lhs = 0;
        for(int rhs = 1; rhs < nums.size(); ++rhs) {
            int &c = cnt[nums[rhs]];
            if(c == k) {
                mx = max(mx, rhs - lhs);
                for(; nums[lhs] != nums[rhs]; ++lhs)
                    cnt[nums[lhs]]--;
                lhs++;
            } else {
                c++;
            }
        }
        mx = max(mx, (int)nums.size() - lhs);
        return mx;
    }
};
