class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int s = 0;       
        int mx = 0;     
        for(auto x : gain) {
            s += x;
            mx = max(mx,s);
        }
        return mx;
    }
};
