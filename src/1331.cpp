class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        unsigned n = arr.size();
        if(n == 0) return vector<int>(); 

        vector<int> index(n);
        iota(index.begin(), index.end(), 0);
        sort(index.begin(), index.end(), [&](size_t x, size_t y) { return arr[x] < arr[y]; });

        vector<int> prerank(n, 0);
        prerank[0] = 1;
        int rlevel = 1;
        int last = arr[index[0]];
        for(int i = 1; i < n; ++i) {
            int cur = arr[index[i]];
            rlevel += cur != last;
            last = cur;
            prerank[i] = rlevel;
        }

        vector<int> grgr(n, 0);
        for(int i = 0; i < n; ++i) {
            grgr[index[i]] = i;
        } 

        for(int i = 0; i < n; ++i) {
           index[i] = prerank[grgr[i]];
        }

        return index;
    }
};
