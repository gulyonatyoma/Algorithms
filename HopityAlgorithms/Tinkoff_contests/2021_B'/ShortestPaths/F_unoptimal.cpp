#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {
    freopen ("dijkstra.in", "rt", stdin);
    freopen ("dijkstra.out", "wt", stdout);
    ll n, s, f, t;
    unordered_map<ll, unordered_map<ll, ll>> graph;
    unordered_map<ll, ll> min_paths;
    cin >> n >> s >> f;
    for (ll i = 1; i <= n; ++i) {
        for (ll j = 1; j <= n; ++j) {
            cin >> t;
            if ((i == j) || (t == -1))
                continue;
            graph[i][j] = t;
        }
    }
    min_paths[s] = 0;
    auto cmp = [](const pair<ll, ll>& a, const pair<ll, ll>& b) {return a.second > b.second; };
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, decltype(cmp)> heap(cmp);
    for (const auto& [key, value] : graph[s])
        heap.push({key, value});
    while (heap.size() != 0) {
        ll vertex = heap.top().first;
        ll distance = heap.top().second;
        heap.pop();
        if (min_paths.find(vertex) != min_paths.end()) {
            min_paths[vertex] = min(min_paths[vertex], distance);
        } else {
            min_paths[vertex] = distance;
        }
        for (const auto& [key, value] : graph[vertex]) {
            if (min_paths.find(key) != min_paths.end()) {
                if (distance + value < min_paths[key]) {
                    heap.push({key, distance + value});
                }
            } else {
                heap.push({key, distance + value});
            }
        }
    }
    if (min_paths.find(f) == min_paths.end())
        cout << -1;
    else
        cout << min_paths[f];
    return 0;
}