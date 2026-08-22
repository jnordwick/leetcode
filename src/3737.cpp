class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        unsigned n = nums.size();
        for(int &x : nums)
            x = x == target ? 1 : -1;
        vector<int> roll(n+1);
        int sum = 0;
        for(int i = 0; i < n; ++i) {
            sum += nums[i];
            roll[i+1] = sum;
        }
        int count = 0;
        for(int lag = 1; lag <= n; ++lag) {
            for(int i = lag; i <= n; ++i) {
                int v = roll[i] - roll[i - lag];
                count += v > 0; 
            }
        }
        return count;
    }
};
