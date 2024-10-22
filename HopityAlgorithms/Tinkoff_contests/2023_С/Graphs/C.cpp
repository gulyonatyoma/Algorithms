#include <bits/stdc++.h>
using namespace std;
#define ll long long


void PseudoTopSort(ll vertex, unordered_map<ll, unordered_map<ll, bool>>& graph,
                    unordered_map<ll, bool>& visited, vector<ll>& topsort) {
    if (visited.find(vertex) != visited.end())
        return;
    visited[vertex] = true;
    for (const auto& [key, value] : graph[vertex])
        PseudoTopSort(key, graph, visited, topsort);
    topsort.push_back(vertex);
}


void CSB(ll vertex, ll prev_vertex, unordered_map<ll, unordered_map<ll, bool>>& graph,
          unordered_map<ll, bool>& visited, vector<ll>& component,
          vector<vector<ll>>& ans, unordered_map<ll, ll>& SNS, bool is_first,
          unordered_map<ll, unordered_map<ll, bool>>& ce, ll& edges) {
    if (visited.find(vertex) != visited.end()) {
        if (is_first) {
            return;
        } else if (prev_vertex != -1) {
            if (ce[SNS[prev_vertex]].find(SNS[vertex]) != ce[SNS[prev_vertex]].end()) {
                return;
            } else if (SNS[prev_vertex] == SNS[vertex]) {
                return;
            }
            ++edges;
            ce[SNS[prev_vertex]][SNS[vertex]] = true;
            return;
        }
    }
    visited[vertex] = true;
    SNS[vertex] = ans.size() + 1;
    for (const auto& [key, value] : graph[vertex]) {
        CSB(key, vertex, graph, visited, component, ans, SNS, 0, ce, edges);
    }
    component.push_back(vertex);
    if (is_first)
        ans.push_back(component);
}


int main() {
    ll n, m, u, v;
    ll edges = 0;
    unordered_map<ll, unordered_map<ll, bool>> graph;
    unordered_map<ll, unordered_map<ll, bool>> t_graph;
    unordered_map<ll, unordered_map<ll, bool>> ce;
    unordered_map<ll, bool> visited;
    vector<vector<ll>> ans;
    unordered_map<ll, ll> SNS;
    vector<ll> topsort;
    cin >> n >> m;
    for (ll i = 0; i < m; ++i) {
        cin >> u >> v;
        graph[u][v] = true;
        t_graph[v][u] = true;
    }
    for (ll vertex = 1; vertex <= n; ++vertex)
        PseudoTopSort(vertex, graph, visited, topsort);
    reverse(topsort.begin(), topsort.end());
    visited.clear();
    for (const auto& vertex : topsort) {
        vector<ll> component;
        component.clear();
        CSB(vertex, -1, t_graph, visited, component, ans, SNS, 1, ce, edges);
    }
    cout << edges;
    return 0;
}