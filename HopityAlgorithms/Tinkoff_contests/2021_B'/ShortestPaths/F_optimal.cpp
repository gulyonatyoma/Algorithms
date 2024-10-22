#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {
    freopen ("dijkstra.in", "rt", stdin);
    freopen ("dijkstra.out", "wt", stdout);
    ll n, s, f, t;
    cin >> n >> s >> f;
    --s;
    --f;
    unordered_map<ll, unordered_map<ll, ll>> graph;
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < n; ++j) {
            cin >> t;
            if ((i == j) || (t == -1)) {
                continue;
            }
            graph[i][j] = t;
        }
    }
    set<pair<ll, ll>> st;
    vector<ll> dist(n, 1000000);
    dist[s] = 0;
    for (ll i = 0; i < n; ++i) {
        if (i != s)
            st.insert({1000000, i});
        else
            st.insert({0, i});
    }
    for (ll i = 0; i < n; ++i) {
        if(st.empty())
            break;
        pair<ll, ll> pr = *st.begin();
        st.erase(st.begin());
        ll vertex = pr.second;
        ll distance = pr.first;
        for (const auto& [key, value] : graph[vertex]) {
            if (distance + value < dist[key]) {
                st.erase(st.find({dist[key], key}));
                st.insert({distance + value, key});
                dist[key] = distance + value;
            }
        }
    }
    if (dist[f] == 1000000) {
        cout << -1;
    } else {
        cout << dist[f];
    }
    return 0;
}