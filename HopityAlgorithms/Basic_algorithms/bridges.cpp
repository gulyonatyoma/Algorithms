#include <bits/stdc++.h>
using namespace std;
#define ll long long


struct Time {
    ll t_in;
    ll t_out;
    ll t_up;
};


void FillTUp(ll vertex, ll ancestor, unordered_map<ll, unordered_map<ll, bool>>& graph,
             unordered_map<ll, bool>& visited, unordered_map<ll, Time>& timers,
             vector<pair<ll, ll>>& ans, ll& time) {
    if ((ancestor == -1) && (visited.find(vertex) != visited.end())) {
        return;
    }
    else if (visited.find(vertex) == visited.end()) {
        visited[vertex] = true;
        timers[vertex].t_in = timers[vertex].t_up = time++;
    }
    for (const auto& [key, value] : graph[vertex]) {
        if (key == ancestor) {
            continue;
        }
        else if (visited.find(key) != visited.end()) {
            timers[vertex].t_up = min(timers[vertex].t_up, timers[key].t_in);
        }
        else {
            FillTUp(key, vertex, graph, visited, timers, ans, time);
            timers[vertex].t_up = min(timers[vertex].t_up, timers[key].t_up);
        }
    }
    if ((ancestor != -1) && timers[vertex].t_up == timers[vertex].t_in) {
        ans.push_back({ancestor, vertex});
    }
}


void FindComponents(ll vertex, unordered_map<ll, unordered_map<ll, bool>>& graph,
                    unordered_map<ll, bool>& visited, vector<ll>& ans, bool is_first) {
    if (visited.find(vertex) != visited.end())
        return;
    visited[vertex] = true;
    for (const auto& [key, value] : graph[vertex]) {
        FindComponents(key, graph, visited, ans, 0);
    }
    ans.push_back(vertex);
}


int main() {
    ll n, m, u, v;
    cin >> n >> m;
    unordered_map<ll, unordered_map<ll, bool>> graph;
    unordered_map<ll, bool> visited;
    unordered_map<ll, Time> timers;
    vector<pair<ll, ll>> ans;
    for (ll i = 0; i < m; ++i) {
        cin >> u >> v;
        graph[u][v] = true;
        graph[v][u] = true;
    }
    ll time = 1;
    for (ll i = 1; i <= n; ++i) {
        FillTUp(i, -1, graph, visited, timers, ans, time);
    }
    cout << "\nGraph has " << ans.size() << " bridges:\n";
    for (const auto& pr : ans) {
        cout << pr.first << ' ' << pr.second << '\n';
    }
    return 0;
}