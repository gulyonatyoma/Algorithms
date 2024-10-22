#include <bits/stdc++.h>
using namespace std;
#define ll long long


void Add(ll x, ll y, unordered_map<ll, unordered_set<ll>>& children,
         unordered_map<ll, ll>& ancestors, unordered_map<ll, ll>& degrees) {
    children[min(x, y)].insert(max(x, y));
    ancestors[max(x, y)] = min(x, y);
    if (degrees.find(x) == degrees.end()) {
        degrees[x] = 1;
    } else {
        ++degrees[x];
    }
    if (degrees.find(y) == degrees.end()) {
        degrees[y] = 1;
    } else {
        ++degrees[y];
    }
}


ll CalculateMaxDistances(unordered_map<ll, unordered_set<ll>>& children, unordered_map<ll, ll>& ancestors,
                         unordered_map<ll, ll>& degrees, unordered_map<ll, ll>& distances,
                         unordered_map<ll, unordered_set<ll>>& children2, unordered_map<ll, ll>& ancestors2,
                         ll N) {
    queue<ll> leaves;
    ll leaf_val = 0;
    ll diameter = 0;
    ll cv1, cv2;
    queue<ll> BFS;
    unordered_map<ll, ll> leaves_vals;
    BFS.push(0);
    cout << "\nBFS process:\n";
    while (!BFS.empty()) {
        ll n = BFS.size();
        for (ll i = 0; i < n; ++i) {
            ll v = BFS.front();
            cout << v << ' ';
            BFS.pop();
            if (degrees[v] == 1) {
                leaves.push(v);
                leaves_vals[v] = leaf_val;
            }
            for (const ll& to : children[v]) {
                BFS.push(to);
            }
        }
        cout << '\n';
    }
    ++leaf_val;
    cout << "\nLeaves process:\n";
    while (!leaves.empty()) {
        ll n = leaves.size();
        if (N == 1) {
            cv1 = leaves.front();
            cv2 = -1;
            cout << cv1 << '\n';
            leaves.pop();
            --leaf_val;
            diameter = leaf_val*2;
            break;
        } else if (N == 2) {
            cv1 = leaves.front();
            leaves.pop();
            cv2 = leaves.front();
            leaves.pop();
            --leaf_val;
            cout << cv1 << ' ' << cv2 << '\n';
            diameter = leaf_val*2 + 1;
            break;
        }
        for(ll i = 0; i < n; ++i) {
            ll leaf = leaves.front();
            --N;
            cout << leaf << ' ';
            leaves.pop();
            if (ancestors[leaf] == leaf) {
                ll child = *(children[leaf].begin());
                ancestors[child] = child;
                --degrees[child];
                --degrees[leaf];
                if (degrees[child] == 1) {
                    leaves_vals[child] = leaf_val;
                    leaves.push(child);
                } 
            } else {
                ll ancestor = ancestors[leaf];
                children[ancestor].erase(children[ancestor].find(leaf));
                --degrees[ancestor];
                --degrees[leaf];
                if (degrees[ancestor] == 1) {
                    leaves_vals[ancestor] = leaf_val;
                    leaves.push(ancestor);
                }
            }
        }
        cout << '\n';
        ++leaf_val;
    }
    if (cv2 == -1) {
        distances[cv1] = leaf_val;
    } else {
        ++leaf_val;
        distances[cv1] = leaf_val;
        distances[cv2] = leaf_val;
    }
    unordered_map<ll, bool> visited;
    visited[cv1] = true;
    BFS.push(cv1);
    if (cv2 != -1) {
        BFS.push(cv2);
        visited[cv2] = true;
    }
    ll layer = 1;
    while(!BFS.empty()) {
        ll n = BFS.size();
        for (ll i = 0; i < n; ++i) {
            ll v = BFS.front();
            BFS.pop();
            if (ancestors2[v] != v) {
                if (visited.find(ancestors2[v]) == visited.end()) {
                    visited[ancestors2[v]] = true;
                    distances[ancestors2[v]] = leaf_val + layer;
                    BFS.push(ancestors2[v]);
                }
            }
            for (const ll& child : children2[v]) {
                if (visited.find(child) == visited.end()) {
                    visited[child] = true;
                    distances[child] = leaf_val + layer;

                    BFS.push(child);
                }
            }
        }
        ++layer;
    }
    return diameter;
}


int main() {
    ll n, x, y;
    unordered_map<ll, unordered_set<ll>> children;
    unordered_map<ll, unordered_set<ll>> children2;
    unordered_map<ll, ll> ancestors;
    unordered_map<ll, ll> ancestors2;
    ancestors[0] = 0;
    ancestors2[0] = 0;
    unordered_map<ll, ll> degrees;
    unordered_map<ll, ll> degrees2;
    unordered_map<ll, ll> distances;
    cin >> n;
    for (ll i = 0; i < n-1; ++i) {
        cin >> x >> y;
        Add(x, y, children, ancestors, degrees);
        Add(x, y, children2, ancestors2, degrees2);
    }
    cout << "\nTree degrees for each vertex:\n";
    for (ll i = 0; i < n; ++i) {
        cout << "deg(" << i << ") = " << degrees[i] << '\n';
    }
    ll diameter = CalculateMaxDistances(children, ancestors, degrees, distances, children2, ancestors2, n);
    cout << "Tree diameter = " << diameter << '\n';
    cout << "Max distances for each vertex:\n";
    for (ll i = 0; i < n; ++i) {
        cout << "maxdist(" << i << ") = " << distances[i] << '\n';
    }
    return 0;
}
