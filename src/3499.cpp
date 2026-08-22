class Solution {
public:

    int maxActiveSectionsAfterTrade(string const &s) {
        int runs0 = numeric_limits<int>::min();
        int runs1 = 0;

        int ones=0, mx=0;
        char last = '1'; 
        for(int i = 0; i < s.size(); ++i) {
            char c = s[i];
            ones += c == '1';
            if(c == '1' && last == '0') {
               mx = max(mx, runs0 + runs1);
            }
            else if(c == '0' && last == '1') {
                swap(runs0, runs1);                
                runs0 = 0;
            }
            runs0 += c == '0';
            last = c;
        }
        mx = max(max(mx, runs0 + runs1), 0);
        return mx + ones;
    }
};

