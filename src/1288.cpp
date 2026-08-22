class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& iv) {
        sort(iv.begin(), iv.end(), [](auto const &x, auto const &y) {
            if(x[0] == y[0]) return x[1] > y[1];
            return x[0] < y[0];
        });
        int count = 1;
        int right = iv[0][1];
        for(int i = 1; i < iv.size(); ++i) {
            if(iv[i][1] > right) {
                count += 1;
                right = iv[i][1]; 
            }
        }
        return count;
    }
};
