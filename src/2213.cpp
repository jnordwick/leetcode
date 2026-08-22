
struct Node {
    uint longest;
    uint lhs, rhs;
    uint lsub, rsub;

    bool is1char() const { return lsub == rhs-lhs+1; }
};


Node merge(string const &s, Node const &lnode, Node const &rnode) {
    Node node;
    if(s[lnode.rhs] != s[rnode.lhs]) {
        node.longest = max(lnode.longest, rnode.longest);
        node.lhs = lnode.lhs, node.rhs = rnode.rhs;
        node.lsub = lnode.lsub, node.rsub = rnode.rsub;
    }
    else {
        uint midlen = lnode.rsub + rnode.lsub;
        node.longest = max(max(lnode.longest, rnode.longest), midlen);
        node.lhs = lnode.lhs, node.rhs = rnode.rhs;
        node.lsub = lnode.is1char() ? midlen : lnode.lsub;
        node.rsub = rnode.is1char() ? midlen : rnode.rsub;
    }
    return node;
}

void build(vector<Node> &tr, string const &s, uint n, uint lhs, uint rhs) {
    if(lhs == rhs) {
        tr[n] = {.longest = 1, .lhs = lhs, .rhs = rhs, .lsub = 1, .rsub = 1};
        return;
    }
    uint lchild = n*2+1, rchild = n*2+2, mid=(rhs+lhs)/2;
    Node &lnode = tr[lchild], &rnode = tr[rchild];

    build(tr, s, lchild, lhs, mid);
    build(tr, s, rchild, mid+1, rhs);
    tr[n] = merge(s, lnode, rnode);
}

void update(vector<Node> &tr, string const &s, uint p, uint n, uint lhs, uint rhs) {
    if(lhs == rhs) return;

    uint lchild = n*2+1, rchild = n*2+2, mid=(rhs+lhs)/2;
    Node &lnode = tr[lchild], &rnode = tr[rchild];

    if(p <= mid) update(tr, s, p, lchild, lhs, mid);
    else update(tr, s, p, rchild, mid+1, rhs);

    tr[n] = merge(s, lnode, rnode);
}

class Solution {
public:
    vector<int> longestRepeating(string s, string qc, vector<int>& qi) {
        vector<Node> tr(4*s.size());
        vector<int> ret(qc.size());

        build(tr, s, 0, 0, s.size()-1); 
        for(uint i = 0; i < qc.size(); ++i) {
            s[qi[i]] = qc[i];
            update(tr, s, qi[i], 0, 0, s.size()-1);
            ret[i] = (int)tr[0].longest;
        }
        return ret;
    }
};
