class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int x = 0, r = 0;  
        for(int i = 0; i < nums.size(); ++i)
            x ^= nums[i], r |= nums[i];
        return !r ? 0 : nums.size() - !x;
    }
};
