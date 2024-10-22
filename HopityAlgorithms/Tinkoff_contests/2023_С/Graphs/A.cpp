#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {
    ll n, m, u, v;
    vector<ll> permutation;
    vector<ll> topsort;
    unordered_map<ll, unordered_map<ll, bool>> graph;
    unordered_map<ll, bool> visited;
    cin >> n >> m;
    for (ll i = 0; i < m; ++i) {
        cin >> u >> v;
        graph[u][v] = true;
    }
    for (ll i = 1; i <= n; ++i) {
        cin >> u;
        permutation.push_back(u);
    }
    bool flag = true;
    for (const auto& vertex : permutation) {
        visited[vertex] = true;
        for (const auto& [key, value] : graph[vertex]) {
            if (visited.find(key) != visited.end()) {
                flag = false;
                break;
            }
        }
    }
    if (flag)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}