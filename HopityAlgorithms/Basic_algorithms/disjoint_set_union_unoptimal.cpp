#include <bits/stdc++.h>
using namespace std;
#define ll long long


struct DSUNode {
    DSUNODE(DSUNode* ancestor_) : val{0}, ancestor{ancestor_}, weight{0} {}
    DSUNODE(ll val_) : val{val_}, ancestor{nullptr}, weight{1} {}
    DSUNODE(ll val_, DSUNode* ancestor_) : val{val_}, ancestor{ancestor_}, weight{0} {}
    ll val;
    ll weight;
    DSUNode* ancestor;
};

DSUNode* _FindSet(DSUNode* element, vector<DSUNode*>& path) {
    if (element->ancestor == nullptr) {
        for (const DSUNode*& el : path) {
            el->ancestor = element;
        }
        return element->val;
    } else {
        path.push_back(element);
        _FindSet(element->ancestor, path);
    }
}

bool _AreSame(DSUNode* a, DSUNode* b) {
    vector<DSUNode*> path;
    DSUNode* a_fs = _FindSet(a, path);
    path.clear();
    DSUNode* b_fs = _FindSet(b, path);
    return a_fs == b_fs;
}


void _Unite(DSUNode* a, DSUNode* b) {
    vector<DSUNode*> path;
    DSUNode* a_rt = _FindSet(a, path);
    path.clear();
    DSUNode* b_rt = _FindSet(b, path);
    if (a_rt != b_rt) {
        if (b_rt->weight >= a_rt->weight) {
            swap(b_rt, a_rt);
        }
        a_rt->weight += b_rt->weight;
        b_rt->weight = 0;
        b_rt->val = 0;
        b_rt->ancestor = a_rt;
    }
}


void _AddElem(DSUNode* element, DSUNode* to) {
    vector<DSUNode*> path;
    DSUNode* root = _FindSet(to, path);
    element->ancestor = root;
    ++(root->weight);
}


ll FindSet(ll element, unordered_map<ll, DSUNode*>& em) {
    vector<DSUNode*> path;
    return (_FindSet(em[element], path))->val;
}


bool AreSame(ll a, ll b, unordered_map<ll, DSUNode*>& em) {
    return _AreSame(em[a], em[b]);
}


void Unite(ll a, ll b, unordered_map<ll, DSUNode*>& em) {
    _Unite(em[a], em[b]);
}


void AddElem(ll element, ll to, unordered_map<ll, DSUNode*>& em) {
    _AddElem(em[element], em[to]);
}


int main() {
    ll n, el;
    cin >> n;
    return 0;
}