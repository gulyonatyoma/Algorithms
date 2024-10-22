#include <bits/stdc++.h>
using namespace std;
#define ll long long


vector<ll> suprefixes(string s) {
    ll n = s.size();
    vector<ll> sf(n, 0);
    for (ll i = 1; i < n; ++i) {
        ll k = sf[i-1];
        while((k > 0) && (s[k] != s[i])) {
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
    ll n, m;
    string str, s, p;
    cin >> n >> m;
    cin >> s >> p;
    str = p + '_' + s;
    for (const char& c : str) {
        cout << c;
    }
    vector<ll> sf = suprefixes(str);
    vector<ll> ins;
    for (ll i = m*2; i < n+m+1; ++i) {
        if (sf[i] == m) {
            ins.push_back(i-m*2);
        }
    }
    cout << "\nSuprefixes lengths:\n";
    for (const ll& supf : sf) {
        cout << supf << ' ';
    }
    cout << "\nFound Pattern at:\n";
    for (const ll& in : ins) {
        cout << in << ' ';
    }
    return 0;
}