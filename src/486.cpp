class Solution {
public:
    static constexpr int empty = std::numeric_limits<int>::min();

    static int& at(int *mem, int n, int x, int y) {
        return mem[x*n + y];
    }

    int eval(vector<int> const &b, int *mem, int n, int pl, int pr) const {
        int &ret = at(mem,n,pl,pr);
        if(ret != empty) return ret;

        int sl = b[pl] - eval(b, mem, n, pl+1, pr);
        int sr = b[pr] - eval(b, mem, n, pl, pr-1);

        return ret = max(sl,sr);
    }

    bool predictTheWinner(vector<int>& nums) {
        int mem[20*20];
        ranges::fill(mem, empty);
        for(int i=0; i < nums.size(); ++i) at(mem,nums.size(),i,i) = nums[i];
        int s = eval(nums, mem, nums.size(), 0, nums.size() - 1);
        return s >= 0;
    }
};
