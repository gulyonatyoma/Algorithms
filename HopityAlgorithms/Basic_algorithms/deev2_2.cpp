#include <bits/stdc++.h>
using namespace std;
#define ll long long


void DFS(ll vertex, unordered_map<ll, unordered_map<ll, bool>>& graph,
         unordered_map<ll, bool>& visited, vector<ll>& dfs_history, ll n) {
    if (visited.find(vertex) != visited.end()) {
        return;
    }
    dfs_history.push_back(vertex);
    visited[vertex] = true;
    for (ll i = 0; i < n; ++i) {
        if (graph[vertex].find(i) != graph[vertex].end())
            DFS(i, graph, visited, dfs_history, n);
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
    vector<ll> dfs;
    for (ll i = 0; i < n; ++i) {
        if (graph.find(i) != graph.end()) {
            DFS(i, graph, visited, dfs, n);
            break;
        }
    }
    for (const auto& vert : dfs) {
        cout << vert << ' ';
    }
    return 0;
}