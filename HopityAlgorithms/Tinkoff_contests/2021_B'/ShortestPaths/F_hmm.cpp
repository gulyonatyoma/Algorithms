#include <bits/stdc++.h>
using namespace std;
#define int int64_t
int32_t main() {
    freopen ("dijkstra.in", "rt", stdin);
    freopen ("dijkstra.out", "wt", stdout);
    int n;
    cin >> n;
    int s,f;
    cin >> s >> f;
    s--;
    f--;
    int a[n][n];
    for(int r=0;r<n;r++) {
        for(int w=0;w<n;w++) {
            cin >> a[r][w];
        }
    }
    vector <int> d(n, 1000000000);
    d[s]=0;
    set <pair<int, int>> b;
    for(int r=0;r<n;r++) {
        if(r!=s) {
            b.insert({1000000000,r});
        }
        else {
            b.insert({0, s});
        }
    }
    for(int r=0;r<n;r++) {
        pair<int, int> w=*b.begin();
        b.erase(b.begin());
        int to=w.second;
        int sum=w.first;
        for(int e=0;e<n;e++) {
            if((to==e) || a[to][e]==-1) {
                continue;
            }
            else {
                if(d[e]>(sum+a[to][e])) {
                    b.erase(b.find({d[e], e}));
                    b.insert({sum+a[to][e], e});
                    d[e]=(sum+a[to][e]);
                }
            }
        }
    }
    if(d[f]==1000000000) {
        cout << -1;
    }
    else {
        cout << d[f];
    }
}