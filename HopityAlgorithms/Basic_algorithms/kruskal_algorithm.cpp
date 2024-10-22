#include <bits/stdc++.h>
using namespace std;
#define ll long long


struct Edge {
    ll from;
    ll to;
    ll weight;
};


ll FindSet(ll item, unordered_map<ll, ll>& ancestors) {
    if (ancestors[item] == item) {
        return item;
    } else {
        ancestors[item] = FindSet(ancestors[item], ancestors);
        return ancestors[item];
    }
}


ll AreSame(ll a, ll b, unordered_map<ll, ll>& ancestors) {
    return (FindSet(a, ancestors) == FindSet(b, ancestors));
}


void Unite(ll a, ll b, unordered_map<ll, ll>& ancestors, unordered_map<ll, ll>& ranks) {
    a = FindSet(a, ancestors);
    b = FindSet(b, ancestors);
    if (a != b) {
        if(ranks[a] < ranks[b]) {
            swap(a, b);
        }
        ancestors[b] = a;
        if (ranks[a] == ranks[b]) {
            ++ranks[a];
        }
    }
}


void AddElement(ll elem, ll to, unordered_map<ll, ll>& ancestors) {
    ancestors[elem] = FindSet(to, ancestors);
}


void CreateRoot(ll root, unordered_map<ll, ll>& ancestors, unordered_map<ll, ll>& ranks) {
    ancestors[root] = root;
    ranks[root] = 1;
}


vector<Edge> Kruskal(set<pair<ll, pair<ll, ll>>>& st) {
    unordered_map<ll, ll> ancestors;
    unordered_map<ll, ll> ranks;
    vector<Edge> result;
    while (!st.empty()) {
        ll u = st.begin()->second.first;
        ll v = st.begin()->second.second;
        ll w = st.begin()->first;
        st.erase(st.begin());
        if ((ancestors.find(u) == ancestors.end()) && (ranks.find(v) == ranks.end())) {
            CreateRoot(u, ancestors, ranks);
            AddElement(v, u, ancestors);
            result.push_back({u, v, w});
        } else if ((ancestors.find(u) != ancestors.end()) && (ancestors.find(v) == ancestors.end())) {
            AddElement(v, u, ancestors);
            result.push_back({u, v, w});
        } else if ((ancestors.find(u) == ancestors.end()) && (ancestors.find(v) != ancestors.end())) {
            AddElement(u, v, ancestors);
            result.push_back({u, v, w});
        } else if ((ancestors.find(u) != ancestors.end()) && (ancestors.find(v) != ancestors.end())) {
            if (!AreSame(u, v, ancestors)) {
                Unite(u, v, ancestors, ranks);
                result.push_back({u, v, w});
            }
        }
    }
    return result;
}

int main() {
    ll n, m, u, v, w;
    set<pair<ll, pair<ll, ll>>> st;
    cin >> n >> m;
    for (ll i = 0; i < m; ++i) {
        cin >> u >> v >> w;
        st.insert({w, {u, v}});
    }
    vector<Edge> answer = Kruskal(st);
    cout << "\nFound MST:\n";
    for (const Edge& edge : answer) {
        cout << edge.from << ' ' << edge.to << ' ' << edge.weight << '\n';
    }
    cout << '\n';
    return 0;
}