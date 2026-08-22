class Solution {
public:
    void recur(vector<int> &v, int p) {
        int place = v[p];
        while(true) {
            if(place <= 0 || place > v.size()) return;
            int next = v[place-1];
            if(next == place) return;
            v[place-1] = place;
            place = next;
        }
    }

    int firstMissingPositive(vector<int>& v) {
        for(int i = 0; i < v.size(); ++i)
            recur(v, i);
        for(int i = 0; i < v.size(); ++i) {
            if(v[i] != i+1) return i+1;
        }
        return v.size()+1;
    }
};

