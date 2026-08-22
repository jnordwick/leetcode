class Solution {
public:
    bool rotateString(string s, string goal) {
        return (goal + goal).contains(s);
    }
};
