class Solution {
public:
    int largestRectangleArea(vector<int>& hs) {
        vector<pair<int,int>> s; // height, start
        int mx = 0;
        hs.push_back(0);
        for(int i = 0; i < hs.size(); ++i) {
            int h = hs[i];
            if(s.empty() || h > s.back().first) {
                s.emplace_back(h, i);
            } else if(h < s.back().first) {
                int t_start;
                while(!s.empty() && s.back().first > h) {
                    int t_height = s.back().first;
                    int t_width = i - s.back().second;
                    t_start = s.back().second;
                    mx = max(mx, t_height * t_width);
                    s.pop_back();
                }
                s.emplace_back(h, t_start);
            }
        }
        return mx;
    }
};
