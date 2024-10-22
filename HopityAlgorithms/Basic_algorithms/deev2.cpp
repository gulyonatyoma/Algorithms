#include <bits/stdc++.h>
using namespace std;
#define ll long long


void DFS(ll vertex, unordered_map<ll, vector<ll>>& graph,
         unordered_map<ll, bool>& visited, vector<vector<ll>>& dfs_history, bool is_first) {
    if (visited.find(vertex) != visited.end()) {
        return;
    }
    visited[vertex] = true;
    if (is_first) {
        dfs_history.push_back({});
        dfs_history.back().push_back(vertex);
    } else {
        dfs_history.back().push_back(vertex);
    }
    for (const auto& key : graph[vertex]) {
        DFS(key, graph, visited, dfs_history, 0);
    }
}


int main() {
    ll n, m, u, v;
    cin >> n >> m;
    unordered_map<ll, vector<ll>> graph;
    unordered_map<ll, bool> visited;
    for (ll i = 0; i < m; ++i) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for (ll i = 0; i < n; ++i) {
        if (!graph[i].empty()) {
            sort(graph[i].begin(), graph[i].end());
        }
    }
    vector<vector<ll>> dfs;
    for (ll i = 0; i < n; ++i)
        DFS(i, graph, visited, dfs, 1);
    for(const auto& comp : dfs) {
        for (const auto& vert : comp) {
            cout << vert << ' ';
        }
        if (!comp.empty())
            cout << '\n';
    }
    return 0;
}