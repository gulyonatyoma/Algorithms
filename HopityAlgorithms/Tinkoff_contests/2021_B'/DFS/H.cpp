#include <bits/stdc++.h>
using namespace std;
#define ll long long


enum color{white, gray, black};


void DFS(ll vertex, unordered_map<ll, unordered_map<ll, bool>>& graph,
         unordered_map<ll, color>& visited, bool& has_cycle)
{
    if(has_cycle)
        return;
    else if(visited.find(vertex) != visited.end())
    {
        if(visited[vertex] == gray)
        {
            has_cycle = true;
            return;
        }
        return;
    }
    visited[vertex] = gray;
    for(const auto& [key, value] : graph[vertex])
        DFS(key, graph, visited, has_cycle);
    visited[vertex] = black;
}


int main()
{
    ll n, m, x, y;
    unordered_map<ll, unordered_map<ll, bool>> graph;
    unordered_map<ll, color> visited;
    unordered_map<ll, bool> verteces;
    cin >> n >> m;
    for(ll i = 0; i < m; ++i)
    {
        cin >> x >> y;
        graph[x][y] = true;
        verteces[x] = true;
        verteces[y] = true;
    }
    bool has_cycle = false;
    for(const auto& [key, value] : verteces)
        DFS(key, graph, visited, has_cycle);
    cout << has_cycle;
    return 0;
}