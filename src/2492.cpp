#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        using node = pair<int, int>;

        vector<vector<node>> gr(n+1);
        for(auto const &r : roads) {
            int src = r[0], dest = r[1], cost = r[2];
            gr[src].emplace_back(dest, cost);
            gr[dest].emplace_back(src, cost);
        }

        // path = len, dest
        vector<char> seen(n+1);
        vector<int> next;
        int mn = numeric_limits<int>::max();
        next.push_back(1);
        seen[1] = true;
        while(!next.empty()) {
            auto i = next.back();
            next.pop_back();
            for(auto const &[dest, cost] : gr[i]) {
                mn = min(mn, cost);
                if(!seen[dest]) {
                    next.push_back(dest);
                    seen[dest] = true;
                }
            }
        }
        return mn;
    }
};
