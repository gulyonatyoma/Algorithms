#include <bits/stdc++.h>
using namespace std;
#define ll long long


enum color{white, gray, black};


void CycleCheck(ll vertex, unordered_map<ll, unordered_map<ll, bool>>& graph,
         unordered_map<ll, color>& visited, bool& has_cycle) {
    if (has_cycle) {
        return;
    } else if (visited.find(vertex) != visited.end()) {
        if (visited[vertex] == gray) {
            has_cycle = true;
        }
        return;
    }
    visited[vertex] = gray;
    for (const auto& [key, value] : graph[vertex])
        CycleCheck(key, graph, visited, has_cycle);
    visited[vertex] = black;
}


void DFS(ll vertex, unordered_map<ll, unordered_map<ll, bool>>& graph,
         unordered_map<ll, bool>& visited, vector<ll>& topsort) {
    if (visited.find(vertex) != visited.end())
        return;
    visited[vertex] = true;
    for (const auto& [key, value] : graph[vertex])
        DFS(key, graph, visited, topsort);
    topsort.push_back(vertex);
}


int main() {
    ll n, m, u, v;
    unordered_map<ll, unordered_map<ll, bool>> graph;
    unordered_map<ll, color> visited_cycle;
    unordered_map<ll, bool> visited;
    vector<ll> topsort;
    cin >> n >> m;
    for (ll i = 0; i < m; ++i) {
        cin >> u >> v;
        graph[u][v] = true;
    }
    bool has_cycle = false;
    for (ll i = 1; i <= n; ++i) {
        CycleCheck(i, graph, visited_cycle, has_cycle);
    }
    if (has_cycle) {
        cout << -1;
    } else {
        for (ll i = 1; i <= n; ++i) {
            DFS(i, graph, visited, topsort);
        }
        reverse(topsort.begin(), topsort.end());
        for (const auto& j : topsort)
            cout << j << ' ';
    }
    return 0;
}