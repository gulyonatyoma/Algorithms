#include <bits/stdc++.h>
using namespace std;
#define ll long long


struct TreapNode {
    ll x;
    ll y;
    TreapNode* l;
    TreapNode* r;
};


void Split(TreapNode* c, ll x, TreapNode*& l, TreapNode*& r) {
    if (c == nullptr) {
        l = nullptr;
        r = nullptr;
    } else if (x < c->x) {
        Split(c->l, x, l, c->l);
        r = c;
    } else {
        Split(c->r, x, c->r, r);
        l = c;
    }
}


void Insert(TreapNode* it, TreapNode*& c) {
    if (c == nullptr) {
        c = it;
    } else if (it->y > c->y) {
        Split(c, it->x, it->l, it->r);
        c = it;
    } else {
        if (it->x < c->x) {
            Insert(it, c->l);
        } else {
            Insert(it, c->r);
        }
    }
}