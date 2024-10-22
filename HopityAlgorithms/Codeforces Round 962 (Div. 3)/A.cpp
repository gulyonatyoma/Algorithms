#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {
    ll n, t;
    vector<ll> ans;
    cin >> n;
    for (ll i = 0; i < n; ++i) {
        cin >> t;
        ans.push_back(ceil(t/(4.0)));
    }
    for(const ll& i : ans) {
        cout << i << '\n';
    }
    return 0;
}