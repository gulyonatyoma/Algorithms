#include <bits/stdc++.h>
using namespace std;
#define ll long long


ll FindSet(ll v, unordered_map<ll, ll>& ancestors) {
    if (v == ancestors[v]) {
        return v;
    } else {
        ancestors[v] = FindSet(ancestors[v], ancestors);
        return ancestors[v];
    }
}

bool AreSame(ll a, ll b, unordered_map<ll, ll>& ancestors) {
    return (FindSet(a, ancestors) == FindSet(b, ancestors));
}

void Unite(ll a, ll b, unordered_map<ll, ll>& ancestors, unordered_map<ll, ll>& ranks) {
    a = FindSet(a, ancestors);
    b = FindSet(b, ancestors);
    if(a != b) {
        if (ranks[a] < ranks[b]) {
            swap(a, b);
        }
        ancestors[b] = a;
        if (ranks[b] == ranks[a]) {
            ++ranks[a];
        }
    }
}

void AddElem(ll elem, ll to, unordered_map<ll, ll>& ancestors) {
    ancestors[elem] = FindSet(to, ancestors);
}

void CreateRoot(ll root, unordered_map<ll, ll>& ancestors, unordered_map<ll, ll>& ranks) {
    ancestors[root] = root;
    ranks[root] = 1;
}

int main() {
    ll n, a, b;
    unordered_map<ll, ll> ancestors;
    unordered_map<ll, ll> ranks;
    unordered_map<ll, ll> roots;
    unordered_map<ll, ll> orders;
    cin >> n;

    for (ll i = 0; i < n; ++i) {
        cin >> a >> b;
        if (roots.find(b) == roots.end()) {
            roots[b] = a;
            orders[a] = b;
            CreateRoot(a, ancestors, ranks);
        } else {
            AddElem(a, roots[b], ancestors);
        }
    }
    Unite(roots[1], roots[2], ancestors, ranks);
    cout << "\nElement : Set:\n";
    for (ll i = 1; i <= n; ++i) {
        cout << i << ": " << orders[FindSet(i, ancestors)] << '\n';
    }
    cout << '\n';
    return 0;
}