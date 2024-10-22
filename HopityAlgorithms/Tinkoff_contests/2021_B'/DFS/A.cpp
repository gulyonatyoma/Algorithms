#include <bits/stdc++.h>
using namespace std;
#define ll long long


void DFS(ll vertex, unordered_map<ll, unordered_map<ll, bool>>& graph,
         unordered_map<ll, bool>& visited, vector<ll>& component,
         vector<vector<ll>>& ans, bool is_first)
{
    if(visited.find(vertex) != visited.end())
        return;
    visited[vertex] = true;
    component.push_back(vertex);
    for(const auto& [key, value] : graph[vertex])
        DFS(key, graph, visited, component, ans, false);
    if(is_first)
    {
        sort(component.begin(), component.end());
        ans.push_back(component);
    }
}


int main()
{
    ll n, m, x, y;
    vector<vector<ll>> ans;
    unordered_map<ll, unordered_map<ll, bool>> graph;
    unordered_map<ll, bool> visited;
    cin >> n >> m;
    for(ll i = 0; i < m; ++i)
    {
        cin >> x >> y;
        graph[x][y] = true;
        graph[y][x] = true;
    }
    for(ll key = 1; key <= n; ++key)
    {
        vector<ll> component;
        component.clear();
        DFS(key, graph, visited, component, ans, true);
    }
    cout << ans.size() << '\n';
    for(const auto& v : ans)
    {
        cout << v.size() << '\n';
        for(const auto& ver : v)
            cout << ver << ' ';
        cout << '\n';
    }
    return 0;
}