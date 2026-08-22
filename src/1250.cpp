class Solution {
public:

    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        static int g[2500];

        unsigned row=grid.size(), col=grid[0].size(), siz=row*col;
        k %= siz;
        if(k == 0) return grid;

        unsigned i = k;
        for(unsigned r = 0; r < row; ++r) {
            for(unsigned c = 0; c < col; ++c) {
                g[i] = grid[r][c];
                if(++i == siz) i = 0;
            }
        }


        i = 0;
        for(unsigned r = 0; r < row; ++r) {
            for(unsigned c = 0; c < col; ++c) {
                grid[r][c] = g[i];
                i += 1;
            }
        }
        return grid;
    }
};
