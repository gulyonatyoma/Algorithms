#include <bits/stdc++.h>
using namespace std;
#define ll long long


struct Edge {
    ll from;
    ll to;
    ll weight;
};


constexpr ll INF = LONG_LONG_MAX;


int main() {
    ll n, m, u, v, w, s, f;
    // unordered_map<ll, unordered_map<ll, ll>> graph;
    vector<Edge> edges;
    vector<ll> distances;
    distances.push_back(INF);
    cin >> n >> m >> s >> f;
    for (ll i = 0; i < m; ++i) {
        cin >> u >> v >> w;
        // graph[u][v] = w;
        edges.push_back({u, v, w});
    }
    for (ll i = 1; i <= n; ++i) {
        distances.push_back(INF);
    }
    distances[s] = 0;
    for (ll k = 0; k < n-1; ++k) {
        vector<ll> next = distances;
        for (const auto& edge : edges) {
            ll from = edge.from;
            ll to = edge.to;
            ll weight = edge.weight;
            if (distances[to] == INF) {
                if (distances[from] != INF) {
                    next[to] = distances[from] + weight;
                }
            } else {
                if (distances[from] != INF) {
                    next[to] = min(distances[to], distances[from] + weight);
                }
            }
        }
        distances = next;
    }
    bool negative_cycle = false;
    // for ( const auto& edge : edges) {
    //     ll from = edge.from;
    //     ll to = edge.to;
    //     ll weight = edge.weight;
    //     if (distances[to] != INF) {
    //         if (distances[from] != INF) {
    //             if (distances[from] + weight < distances[to]) {
    //                 negative_cycle = true;
    //             }
    //         }
    //     }
    // }
    if (negative_cycle) {
        cout << "\nNegative cycle\n";
    } else {
        cout << "s = " << s << ", f = " << f;
        cout << "\ndist(s, f) = " << distances[f];
        cout << "\nOther distances:\n";
        for (ll i = 1; i <= n; ++i) {
            cout << distances[i] << ' ';
        }
    }
    return 0;
}