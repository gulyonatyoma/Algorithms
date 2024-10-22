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
             unordered_map<ll, ll> children_amount, vector<ll>& ans, ll& time) {
    if ((ancestor == -1) && (visited.find(vertex) != visited.end())) {
        return;
    } else if (ancestor != -1) {
        if (children_amount.find(ancestor) == children_amount.end()) {
            children_amount[ancestor] = 1;
        } else {
            ++children_amount[ancestor];
        }
    }
    bool is_bridge_point = false;
    visited[vertex] = true;
    timers[vertex].t_in = timers[vertex].t_up = time++;
    for (const auto& [key, value] : graph[vertex]) {
        if (key == ancestor) {
            continue;
        } else if (visited.find(key) != visited.end()) {
            timers[vertex].t_up = min(timers[vertex].t_up, timers[key].t_in);
        } else {
            FillTUp(key, vertex, graph, visited, timers, children_amount, ans, time);
            timers[vertex].t_up = min(timers[vertex].t_up, timers[key].t_up);
            if (timers[key].t_up >= timers[vertex].t_in) {
                is_bridge_point = true;
            }
        }
    }
    if (ancestor == -1) {
        if (children_amount[vertex] >= 2) {
            ans.push_back(vertex);
        }
    } else if (is_bridge_point) {
        ans.push_back(vertex);
    }
}


int main() {
    ll n, m, u, v;
    cin >> n >> m;
    unordered_map<ll, unordered_map<ll, bool>> graph;
    unordered_map<ll, bool> visited;
    unordered_map<ll, Time> timers;
    unordered_map<ll, ll> children_amount;
    vector<ll> ans;
    ll time = 1;
    for (ll i = 0; i < m; ++i) {
        cin >> u >> v;
        graph[u][v] = true;
        graph[v][u] = true;
    }
    for (ll i = 1; i <= n; ++i) {
        FillTUp(i, -1, graph, visited, timers, children_amount, ans, time);
    }
    cout << "\nAmount of bridge points: " << ans.size() << "\nBridge points:\n";
    for (const ll& bp : ans) {
        cout << bp << ' ';
    }
    cout << '\n';
    return 0;
}