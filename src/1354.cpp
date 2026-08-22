class Solution {
public:

    bool isPossible(vector<int>& target) {
        if(target.size() == 1) return target[0] == 1;
        uint64_t tot = 0;
        vector<uint64_t> store;
        store.reserve(target.size());
        for(int i = 0; i < target.size(); ++i) {
            tot += target[i];
            if(target[i] > 1) store.push_back(target[i]);
        }
        priority_queue<uint64_t,vector<uint64_t>> heap(less<uint64_t>(), std::move(store));

        while(!heap.empty()) {
            uint64_t topv = heap.top();
            uint64_t rest = tot - topv;
            if(rest == 1) return true;
            heap.pop();
            if(topv <= rest) return false;
            uint64_t residue = topv % rest;
            if(residue == 0) return false;
            tot -= topv - residue;
            if(residue > 1) {
                heap.push(residue);
            }
        }

        return true;
    }
};
