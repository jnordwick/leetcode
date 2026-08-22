class Solution {
public:
    int numberOfSubstrings(string s) {
        uint freq[3] = {}, rhs = 0, cnt = 0;
        freq[s[0]-'a']++;
        for(uint lhs=0; lhs <= s.size()-3; ++lhs) {
            while(freq[0]<1 | freq[1]<1 | freq[2]<1) {
                if(rhs == s.size()-1) goto ret;
                freq[s[++rhs]-'a']++;
            }
            cnt += s.size() - rhs;
            freq[s[lhs]-'a']--;
        }
        ret: return cnt;
    }

};
