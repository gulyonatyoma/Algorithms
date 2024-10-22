#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main()
{
    ll n, m, s, t, u, v, w;
    unordered_map<ll, unordered_map<ll, ll>> graph;
    unordered_map<ll, unordered_map<ll, ll>> t_graph;
    vector<vector<ll>> dp;
    cin >> n >> m >> s >> t;
    for (ll i = 0; i < m; ++i) {
        cin >> u >> v >> w;
        graph[u][v] = w;
        t_graph[v][u] = w;
    }
    for(ll i = 0; i < n; ++i)
        for(ll j = 0; j < n; ++j)
        dp[i][j] = -1;
    dp[s][0] = 0;
    for (ll k = 1; k <= n - 1; ++k) {
        for (ll j = 1; j <= n; ++j) {
        }
        // for(const auto& [key, value] : t_graph[])
    }
    return 0;
}