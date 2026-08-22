
inline uint64_t setbit(uint64_t x, int i) {
    return x
}

class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int sum = nums[0];
        int p = 1;

        while (p < nums.size() && nums[p] == nums[p - 1] + 1)
            sum += nums[p++];

        bool seen[50] = {};

        for (int i = p - 1; i < nums.size(); ++i)
            if (nums[i] >= sum)
                seen[nums[i] - sum] = true;

        for (int i = 0; i < 50; ++i)
            if (!seen[i])
                return sum + i;

        return sum + 50;
    }
};
