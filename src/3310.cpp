class Solution {
public:

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& inv) {
        vector<int> vi(n+1, 0);
        vector<int> ed(inv.size(), 0);
        for(auto const &v : inv) vi[v[0]]++;
        for(int i = 1; i < vi.size(); ++i) vi[i] += vi[i-1];
        vi.insert(vi.begin(), 0);
        vector<int> cur = vi;
        for(auto const &v : inv) ed[cur[v[0]]++] = v[1];

        vector<bool> sus(n);
        vector<int> stack;
        sus[k] = true;
        stack.push_back(k);
        while(!stack.empty()) {
            int s = stack.back();
            stack.pop_back();
            for(int c = vi[s]; c < vi[s+1]; ++c) {
                if(!sus[ed[c]]) sus[ed[c]]=true, stack.push_back(ed[c]);
            }
        }

        vector<int> ret;
        for(int i = 0; i < n; ++i) {
            if(sus[i]) continue;
            for(int j = vi[i]; j < vi[i+1]; ++j) {
                if(sus[i] != sus[ed[j]]) goto ret_all;
            }
        }

        ret.reserve(n);
        for(int i = 0; i < n; ++i) {
            if(!sus[i]) ret.push_back(i);
        }
        return ret;

        ret_all:
        ret.resize(n);
        for(int i = 0; i < n; ++i) ret[i] = i;
        return ret;
    }
};
