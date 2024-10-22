#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {
    ll n, p;
    string str, pattern;
    vector<ll> ans;
    cin >> n >> p >> str >> pattern;
    ll modulos = p*p + 1;
    ll x = 2;
    ll powx = 1;
    ll p_hash = 0;
    ll substr_hash = 0;
    for (ll i = 0; i < p; ++i) {
        p_hash = (p_hash + pattern[i]*powx)%modulos;
        substr_hash = (substr_hash + str[i]*powx)%modulos;
        powx *= x;
    }
    powx /= x;
    if (p_hash == substr_hash) {
        if (str.substr(0, p) == pattern) {
            ans.push_back(0);
        }
    }
    for (ll i = p; i < n; ++i) {
        substr_hash -= str[i-p];
        substr_hash /= x;
        substr_hash = (substr_hash + powx*str[i])%modulos;
        if (substr_hash == p_hash) {
            if (str.substr(i-p+1, p) == pattern) {
                ans.push_back(i-p+1);
            }
        }
    }
    cout << "\nFound Pattern at:\n";
    for (const ll& pos : ans) {
        cout << pos << ' ';
    }
    return 0;
}