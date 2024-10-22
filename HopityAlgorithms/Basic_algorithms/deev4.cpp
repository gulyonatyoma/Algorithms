#include <bits/stdc++.h>
using namespace std;
#define ll long long

enum color {none, odd, even};

void BFS(ll vertex, unordered_map<ll, vector<ll>>& graph,
         unordered_map<ll, bool>& visited, unordered_map<ll, color>& colors, bool& contradiction) {
    if (contradiction) {
        return;
    }
    if (visited.find(vertex) != visited.end()) {
        return;
    }
    queue<ll> bfsq;
    bfsq.push(vertex);
    colors[vertex] = even;
    while(!bfsq.empty()) {
        ll num = bfsq.size();
        for(ll i = 0; i < num; ++i) {
            ll currvert = bfsq.front();
            color col;
            if (colors[currvert] == even) {
                col = odd;
            } else {
                col = even;
            }
            for (const ll& vert : graph[currvert]) {
                if (visited.find(vert) != visited.end()) {
                    continue;
                }
                if (colors.find(vert) == colors.end()) {
                    colors[vert] = col;
                } else {
                    if (colors[vert] != col) {
                        contradiction = true;
                        return;
                    }
                }
                bfsq.push(vert);
            }
            visited[currvert] = true;
            bfsq.pop();
        }
    }
}
int main() {
    ll n, m, u, v;
    cin >> n >> m;
    unordered_map<ll, vector<ll>> graph;
    unordered_map<ll, bool> visited;
    unordered_map<ll, color> colors;
    for (ll i = 0; i < m; ++i) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    bool contradiction = 0;
    for (ll i = 0; i < n; ++i) {
        BFS(i, graph, visited, colors, contradiction);
    }
    if (contradiction) {
        cout << "Graph is not bipartite";
    } else {
        cout << "Graph is bipartite";
    }
    return 0;
}