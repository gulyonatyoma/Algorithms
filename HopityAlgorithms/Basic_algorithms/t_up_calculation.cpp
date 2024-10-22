#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct Time {
    ll t_in;
    ll t_out;
    ll t_up;
};


void t_in_calculation(ll vertex, unordered_map<ll, unordered_map<ll, bool>>& graph,
                      unordered_map<ll, Time>& visited, ll& time) {
    if (visited.find(vertex) != visited.end())
        return;
    visited[vertex] = {time++, -1, -1};
    for (const auto& [key, value] : graph[vertex]) {
        ++time;
        t_in_calculation(key, graph, visited, time);
    }
    ++time;
    visited[vertex].t_out = time;
}


void t_out_calculation(ll vertex, ll ancestor, unordered_map<ll, unordered_map<ll, bool>>& graph,
                       unordered_map<ll, bool>& visited, unordered_map<ll, Time>& timers,
                       ll& time) {
    if ((visited.find(vertex) != visited.end()) && (ancestor == -1)) {
        return;
    } else if (visited.find(vertex) == visited.end()) {
        visited[vertex] = true;
        timers[vertex].t_in = timers[vertex].t_up = time++;
    }
    for (const auto& [key, value] : graph[vertex]) {
        if(key == ancestor) {
            continue;
        } else if (visited.find(key) != visited.end()) {
            timers[vertex].t_up = min(timers[vertex].t_up, timers[key].t_in);
        } else {
            t_out_calculation(key, vertex, graph, visited, timers, time);
            timers[vertex].t_up = min(timers[vertex].t_up, timers[key].t_up);
        }

    }
}


int main() {
    ll n, m, u, v;
    cin >> n >> m;
    unordered_map<ll, unordered_map<ll, bool>> graph;
    unordered_map<ll, bool> visited;
    unordered_map<ll, Time> timers;
    ll time = 1;
    for (ll i = 0; i < m; ++i) {
        cin >> u >> v;
        graph[u][v] = true;
        graph[v][u] = true;
    }
    for (ll i = 1; i <= n; ++i) {
        t_out_calculation(i, -1, graph, visited, timers, time);
    }
    cout << "graph t_in\'s:\n";
    for (ll i = 1; i <= n; ++i) {
        cout << timers[i].t_in << ' ';
    }
    cout << "\ngraph t_up\'s:\n";
    for (ll i = 1; i <= n; ++i) {
        cout << timers[i].t_up << ' ';
    }
    return 0;
}