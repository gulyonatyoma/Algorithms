#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {
    ll n, m, u, v;
    cin >> n >> m;
    unordered_map<ll, unordered_map<ll, bool>> graph;
    unordered_map<ll, bool> visited;
    vector<vector<ll>> ans;
    vector<ll> component;
    for (ll i = 0; i < m; ++i) {
        cin >> u >> v;
        graph[u][v] = true;
        graph[v][u] = true;
    }
    for (ll i = 0; i < n; ++i) {
        if (!(graph[i].empty())) {
            vector<ll> tmp;
            for (const auto& [key, value] : graph[i]) {
                tmp.push_back(key);
            }
            sort(tmp.begin(), tmp.end());
            for (const auto& vert : tmp) {
                cout << vert << ' ';
            }
        } else {
            cout << '-';
        }
        cout << '\n';
    }
    return 0;
}