#include <bits/stdc++.h>
using namespace std;
#define ll long long


void PTS(ll vertex, unordered_map<ll, unordered_map<ll, bool>>& graph,
         unordered_map<ll, bool>& visited, vector<ll>& topsort) {
    if (visited.find(vertex) != visited.end())
        return;
    visited[vertex] = true;
    for (const auto& [key, value] : graph[vertex])
        PTS(key, graph, visited, topsort);
    topsort.push_back(vertex);
}

void CSB(ll vertex, unordered_map<ll, unordered_map<ll, bool>>& graph,
         unordered_map<ll, bool>& visited, unordered_map<ll, ll>& SNS,
         ll& amount, bool first) {
    if (visited.find(vertex) != visited.end())
        return;
    SNS[vertex] = amount + 1;
    visited[vertex] = true;
    for (const auto& [key, value] : graph[vertex])
        CSB(key, graph, visited, SNS, amount, 0);
    if (first)
        ++amount;
}

int main() {
    ll n, m, u, v;
    ll amount = 0;
    unordered_map<ll, unordered_map<ll, bool>> graph;
    unordered_map<ll, unordered_map<ll, bool>> t_graph;
    unordered_map<ll, bool> visited;
    unordered_map<ll, ll> SNS;
    vector<ll> topsort;
    cin >> n >> m;
    for (ll i = 0; i < m; ++i) {
        cin >> u >> v;
        graph[u][v] = true;
        t_graph[v][u] = true;
    }
    for (ll vertex = 1; vertex <= n; ++vertex) {
        PTS(vertex, graph, visited, topsort);
    }
    reverse(topsort.begin(), topsort.end());
    visited.clear();
    for (const ll& vertex : topsort) {
        CSB(vertex, t_graph, visited, SNS, amount, 1);
    }
    cout << amount << '\n';
    for (ll vertex = 1; vertex <= n; ++vertex)
        cout << SNS[vertex] << ' ';
    return 0;
}