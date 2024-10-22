#include <bits/stdc++.h>
using namespace std;
#define ll long long


enum color {white, gray, black};


void DFS(ll vertex, unordered_map<ll, unordered_map<ll, bool>>& graph,
         unordered_map<ll, color>& visited, vector<ll>& topsort, bool& cycle) {
    if (cycle) {
        return;
    } else if (visited.find(vertex) != visited.end()) {
        if (visited[vertex] == gray) {
            cycle = true;
            return;
        }
        return;
    }
    visited[vertex] = gray;
    for (const auto& [key, value] : graph[vertex]) {
        DFS(key, graph, visited, topsort, cycle);
    }
    visited[vertex] = black;
    topsort.push_back(vertex);
}


int main()
{
    ll n, m, u, v;
    unordered_map<ll, unordered_map<ll, bool>> graph;
    unordered_map<ll, color> visited;
    vector<ll> topsort;
    bool cycle = false;
    cin >> n >> m;
    for (ll i = 0; i < m; ++i) {
        cin >> u >> v;
        graph[u][v] = true;
    }
    for (ll i = 1; i <= n; ++i) {
        DFS(i, graph, visited, topsort, cycle);
    }
    reverse(topsort.begin(), topsort.end());
    if (cycle) {
        cout << "\nNo topology sort possible (graph has a cycle)\n";
    } else {
        cout << "\nFound topology sort:\n";
        for (ll i = 0; i < n; ++i) {
            cout << topsort[i] << ' ';
        }
    }
    return 0;
}