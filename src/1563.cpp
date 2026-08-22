class Solution {
public:

    vector<int> mem;

    int score(vector<int> const &ss, vector<int> const &csum, int l, int r) {
        if(l == r) return 0;
        int ml, mr, mx = 0;

        if(mem[l*ss.size() + r] != -1) {
            return mem[l*ss.size() + r]; 
        }

        for(int i = l; i < r; ++i) {
            int lhs = csum[i] - (l == 0 ? 0 : csum[l-1]);
            int rhs = csum[r] - csum[i];
            if(lhs <= rhs) {
                int sc = lhs;
                int sc2  = score(ss, csum, l, i);
                sc += sc2;
                if(sc > mx) {
                    mx = sc;
                    ml = l, mr = i;
                }
            }
            if (rhs <= lhs) {
                int sc = rhs;
                int sc2 = score(ss, csum, i+1, r);
                sc += sc2;
                if(sc > mx) {
                    mx = sc;
                    ml = i+1, mr = r;                    
                }
            }
        }
        mem[l*ss.size() + r] = mx;
        return mx;
    } 

    int stoneGameV(vector<int>& vals) {
        mem.resize(vals.size()*vals.size());
        fill(mem.begin(), mem.end(), -1);
        vector<int> sums(vals.size());
        int sum = 0;
        for(int i = 0; i < vals.size(); ++i) {
            sum += vals[i];
            sums[i] = sum;
        }
        int s = score(vals, sums, 0, vals.size() - 1);
        return s;
    }
};
