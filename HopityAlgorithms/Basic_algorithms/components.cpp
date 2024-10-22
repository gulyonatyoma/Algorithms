#include <bits/stdc++.h>
using namespace std;
#define ll long long


void FindComponents(ll vertex, unordered_map<ll, unordered_map<ll, bool>>& graph,
                    unordered_map<ll, bool>& visited, vector<ll>& component,
                    vector<vector<ll>>& ans, bool first) {
    if (visited.find(vertex) != visited.end())
        return;
    visited[vertex] = true;
    component.push_back(vertex);
    for (const auto& [key, value] : graph[vertex]) {
        FindComponents(key, graph, visited, component, ans, 0);
    }
    if (first) {
        sort(component.begin(), component.end());
        ans.push_back(component);
        component.clear();
    }
}


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
    for (ll i = 1; i <= n; ++i) {
        FindComponents(i, graph, visited, component, ans, 1);
    }
    cout << "\nFound " << ans.size() << " Components:\n";
    for (unsigned ll i = 0; i < ans.size(); ++i) {
        cout << i+1 << ": ";
        for (const ll& j : ans[i]) {
            cout << j << ' ';
        }
        cout << '\n';
    }
    return 0;
}