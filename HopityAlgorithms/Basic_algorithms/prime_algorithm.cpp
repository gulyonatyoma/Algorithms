#include <bits/stdc++.h>
using namespace std;
#define ll long long


// Works only for bond graphs


struct Edge {
    ll from;
    ll to;
    ll weight;
};


vector<Edge> Prime(ll vertex, unordered_map<ll, unordered_map<ll, ll>>& graph) {
    unordered_map<ll, bool> visited;
    set<pair<ll, pair<ll, ll>>> st;
    vector<Edge> result;
    visited[vertex] = true;

    for (const auto& [key, value] : graph[vertex]) {
        st.insert({value, {vertex, key}});
    }
    while (!st.empty()) {
        ll u = (*st.begin()).second.first;
        ll v = (*st.begin()).second.second;
        ll w = (*st.begin()).first;
        st.erase(st.begin());
        if (visited.find(v) == visited.end()) {
            result.push_back({u, v, w});
            visited[v] = true;
            for (const auto& [key, value] : graph[v]) {
                st.insert({value, {v, key}});
            }
        }
    }
    return result;
}


int main() {
    ll n, m, u, v, w;
    unordered_map<ll, unordered_map<ll, ll>> graph;
    cin >> n >> m;
    for (ll i = 0; i < m; ++i) {
        cin >> u >> v >> w;
        graph[u][v] = w;
        graph[v][u] = w;
    }
    vector<Edge> answer = Prime(1, graph);
    cout << "\nFound MST:\n";
    for (const Edge& edge : answer) {
        cout << edge.from << ' ' << edge.to << ' ' << edge.weight << '\n';
    }
    cout << '\n';
    return 0;
}