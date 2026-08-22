class Solution {
public:

    int eval(vector<int> const &sv, vector<int> const &tab, int n) {
        int t1 = sv[n] - tab[n+1];
        int t2 = sv[n] + sv[n+1] - tab[n+2];
        int t3 = sv[n] + sv[n+1] + sv[n+2] - tab[n+3];
        int m = max(max(t1, t2), t3);
        return m;
    }

    string stoneGameIII(vector<int>& sv) {
        int n = sv.size();
        vector<int> tab(n+2, 0);
        tab[n-1] = sv[n-1];
        if(sv.size() == 1) goto end;
        tab[n-2] = max(sv[n-2] - tab[n-1], sv[n-2] + sv[n-1]);
        if(sv.size() == 2) goto end;
        for(int i = n - 3; i >= 0; --i) {
            tab[i] = eval(sv, tab, i);
        }

        end:
        if(tab[0] > 0) return "Alice";
        else if(tab[0] < 0) return "Bob";
        else return "Tie";
    }
};
