#include <bits/stdc++.h>
using namespace std;
#define ll long long


struct Node {
    ll ord;
    vector<Node*> children;
};


void Add(ll x, ll y, unordered_map<ll, vector<ll>>& children, unordered_map<ll, ll>& ancestors) {
    children[min(x, y)].push_back(max(x, y));
    ancestors[max(x, y)] = min(x, y);
}

void SetEverything(ll from, unordered_map<ll, vector<ll>>& children,
                   unordered_map<ll, ll>& childsum, ll depth, ll& dp_base) {
    childsum[from] = 0;
    dp_base += depth;
    for (const ll& to : children[from]) {
        SetEverything(to, children, childsum, depth + 1, dp_base);
        childsum[from] += childsum[to] + 1;
    }
}

void SetDistancesSum(ll from, unordered_map<ll, vector<ll>>& children, unordered_map<ll, ll>& ancestors,
                     unordered_map<ll, ll>& childsum, unordered_map<ll, ll>& distsum, ll n) {
    if (ancestors[from] != from) {
        distsum[from] = distsum[ancestors[from]] + n - 2 - 2*childsum[from];
    }
    for (const ll& to : children[from]) {
        SetDistancesSum(to, children, ancestors, childsum, distsum, n);
    }

}

int main() {
    ll n, x, y;
    unordered_map<ll, vector<ll>> children;
    unordered_map<ll, ll> ancestors;
    unordered_map<ll, ll> childsum;
    unordered_map<ll, ll> distsum;
    ancestors[0] = 0;
    cin >> n;
    for (ll i = 0; i < n-1; ++i) {
        cin >> x >> y;
        Add(x, y, children, ancestors);
    }
    SetEverything(0, children, childsum, 0, distsum[0]);
    SetDistancesSum(0, children, ancestors, childsum, distsum, n);
    cout << "\nCalculated distsums:\n";
    for(ll i = 0; i < n; ++i) {
        cout << "distsum[" << i << "] = " << distsum[i] << '\n';
    }
    return 0;
}
