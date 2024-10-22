#include <bits/stdc++.h>
using namespace std;
#define ll long long


vector<ll> suprefixes(string s, ll n) {
    vector<ll> sf(n, 0);
    for (ll i = 1; i < n; ++i) {
        ll k = sf[i-1];
        while ((k > 0) && (s[i] != s[k])) {
            k = sf[k-1];
        }
        sf[i] = k;
        if (s[i] == s[k]) {
            ++sf[i];
        }
    }
    return sf;
}


int main() {
    ll n;
    string s;
    cin >> n >> s;
    vector<ll> sf = suprefixes(s, n);
    cout << "suprefixes lengths:\n";
    for (const ll& p : sf) {
        cout << p << ' ';
    }
    return 0;
}