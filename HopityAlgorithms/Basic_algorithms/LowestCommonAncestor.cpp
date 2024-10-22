#include <bits/stdc++.h>
using namespace std;
#define ll long long


void DFS(ll vertex, unordered_map<ll, vector<ll>>& children, unordered_map<ll, ll>& ancestors,
         unordered_map<ll, ll>& first, vector<ll>& h, vector<ll>& order, ll height, bool is_first) {
    if (is_first && (ancestors.find(vertex) != ancestors.end()))
        return;
    else if (first.find(vertex) != first.end())
        return;
    first[vertex] = h.size();
    h.push_back(height);
    order.push_back(vertex);
    for (const ll& to : children[vertex]) {
        DFS(to, children, ancestors, first, h, order, height + 1, 0);
        h.push_back(height);
        order.push_back(vertex);
    }
}


int main() {
    ll N, n, u, v;
    unordered_map<ll, vector<ll>> children;
    unordered_map<ll, ll> ancestors;
    unordered_map<ll, ll> first;
    vector<ll> h, order;
    cin >> N;
    for (ll i = 0; i < N; ++i) {
        cin >> u >> n;
        children[u] = {};
        for (ll j = 0; j < n; ++j) {
            cin >> v;
            children[u].push_back(v);
            ancestors[v] = u;
        }
    }
    for (ll i = 1; i <= N; ++i) {
        DFS(i, children, ancestors, first, h, order, 0, 1);
    }
    cout << "\nH:\n";
    for (const ll& height : h) {
        cout << height << ' ';
    }
    cout << "\nFirst:\n";
    for (ll i = 1; i <= N; ++i) {
        cout << first[i] << ' ';
    }
    cout << "\nOrder:\n";
    for (const ll& ord : order) {
        cout << ord << ' ';
    }
    cout << '\n';
    return 0;
}
