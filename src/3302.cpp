class Solution {
public:
    vector<int> validSequence(string str, string pat) {
        vector<int> suf(pat.size(), -1);
        int j = pat.size() - 1;
        for(int i = str.size() - 1; i >= 0; --i) {
            if(j >= 0 && str[i] == pat[j]) {
                suf[j] = i;
                j--;
            }
        }
        suf.push_back(str.size());

        vector<int> ret;

        int f = 0;
        bool skipped = false;
        for(int i = 0; i < str.size(); ++i) {
            if(f == pat.size()) break;
            if(str[i] == pat[f]) {
                ret.push_back(i);
                f++;
            }
            else {
                if(!skipped && suf[f+1] > i) {
                    ret.push_back(i);
                    f++;
                    skipped = true;
                }
            }
        }

        return f == pat.size() ? ret : vector<int>();
    }
};
