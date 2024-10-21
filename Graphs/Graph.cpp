#include <bits/stdc++.h>

using namespace std;

#define int long long

struct Edge {
    int from, to, weight;
};

struct Graph {
    int n, m;
    int start, end;
    vector<vector<int>> gr;
    vector<vector<pair<int, int>>> directed_graph;
    vector<int> used;
    vector<int> color;
    vector<int> parents;
    vector<int> topsort;
    vector<vector<int>> comps;
    vector<int> dist;
    int cnt = 0;

    void read_WUG() {  // взвешенный неориентированный
        cin >> n >> m;
        cin >> start >> end;
        directed_graph.resize(n + 1);
        used.resize(n + 1, 0);
        color.resize(n + 1, 0);
        parents.resize(n + 1, -1);
        comps.resize(n + 1);
        for (int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            directed_graph[u].push_back({v, w});
            directed_graph[v].push_back({u, w});
        }
    }

    void read_WDG() {  // взвешенный ориентированный
        cin >> n >> m;
        directed_graph.resize(n + 1);
        used.resize(n + 1, 0);
        color.resize(n + 1, 0);
        parents.resize(n + 1, -1);
        comps.resize(n + 1);
        for (int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            directed_graph[u].push_back({v, w});
        }
    }

    void read_UUG() {  // невзвешенный неориентированный
        cin >> n >> m;
        gr.resize(n + 1);
        used.resize(n + 1, 0);
        color.resize(n + 1, 0);
        parents.resize(n + 1, -1);
        comps.resize(n + 1);
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            gr[u].push_back(v);
            gr[v].push_back(u);
        }
    }

    void read_UDG() {  // невзвешенный ориентированный
        cin >> n >> m;
        gr.resize(n + 1);
        used.resize(n + 1, 0);
        color.resize(n + 1, 0);
        parents.resize(n + 1, -1);
        comps.resize(n + 1);
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            gr[u].push_back(v);
        }
    }

    bool is_cycle = false;

    void dfs(int u, int count) {
        used[u] = 1;
        comps[count].push_back(u);
        for (auto it : gr[u]) {
            if (!used[it]) {
                dfs(it, count);
            }
        }
        topsort.push_back(u);
    }

    vector<vector<int>> components() {
        for (int i = 1; i <= n; i++) {
            if (!used[i]) {
                dfs(i, cnt++);
            }
        }
        return comps;
    }

    vector<int> topological_sort() {
        cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (!used[i]) {
                dfs(i, cnt++);
            }
        }
        reverse(topsort.begin(), topsort.end());
        return topsort;
    }

    pair<vector<int>, vector<int>> shortest_path_Dijkstra() {
        dist.resize(n + 1, 1e18);
        dist[start] = 0;
        set<pair<int, int>> q;
        q.insert({0, start});
        while (!q.empty()) {
            int v = q.begin()->second;
            q.erase(q.begin());
            for (size_t j = 0; j < directed_graph[v].size(); j++) {
                int to = directed_graph[v][j].first, len = directed_graph[v][j].second;
                if (dist[v] + len < dist[to]) {
                    q.erase(make_pair(dist[to], to));
                    dist[to] = dist[v] + len;
                    parents[to] = v;
                    q.insert(make_pair(dist[to], to));
                }
            }
        }
        return {dist, parents};
    }

    pair<vector<int>, vector<int>> restore_path() {
        int cp = end;
        auto it = shortest_path_Dijkstra();
        vector<int> distances = it.first;
        vector<int> parents = it.second;
        vector<int> way;
        while (parents[cp] != -1) {
            way.push_back(cp);
            cp = parents[cp];
        }
        way.push_back(start);
        reverse(way.begin(), way.end());
        return {distances, way};
    }

    vector<int> Ford_Bellman() {
        cin >> n >> m;

    }
};

void solve() {
    Graph a;
    a.read_WUG();
    auto it = a.restore_path();
    vector<int> dist = it.first;
    vector<int> way = it.second;
    if (dist[a.end] == 1e18) {
        cout << -1;
        return;
    }
    cout << dist[a.end] << ' ' << way.size() << '\n';
    for (auto it : way) {
        cout << it << ' ';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test = 1;

    for (int i = 1; i <= test; i++) {
        cerr << "Test #" << i << '\n';
        solve();
        cout << '\n';
    }

    return 0;
}
