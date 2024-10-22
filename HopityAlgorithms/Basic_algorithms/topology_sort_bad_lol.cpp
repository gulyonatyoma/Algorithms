#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct Time
{
    ll t_in;
    ll t_out;
};

struct Vertex
{
    ll order;
    ll t_in;
    ll t_out;
};

void DFS(ll vertex, unordered_map<ll, unordered_map<ll, bool>>& graph,
         unordered_map<ll, Time>& visited, vector<Vertex>& topology_sort, ll& time)
{
    if(visited.find(vertex) != visited.end())
        return;
    visited[vertex].t_in = time;
    for(const auto& [key, value] : graph[vertex])
    {
        ++time;
        DFS(key, graph, visited, topology_sort, time);
    }
    ++time;
    visited[vertex].t_out = time;
    topology_sort.push_back({vertex, visited[vertex].t_in, visited[vertex].t_out});
}

int main()
{
    ll start, t, n, m;
    unordered_map<ll, unordered_map<ll, bool>> graph;
    unordered_map<ll, Time> visited;
    vector<Vertex> topology_sort;
    cin >> t;
    for(ll i = 0; i < t; ++i)
    {
        cin >> n >> m;
        graph[n][m] = true;
    }
    ll time = 1;
    DFS(1, graph, visited, topology_sort, time);
    reverse(topology_sort.begin(), topology_sort.end());
    for(const auto& v : topology_sort)
        cout << v.order << ' ';
    return 0;
}