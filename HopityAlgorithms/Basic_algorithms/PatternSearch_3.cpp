#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll m, n, p_hash, s_hash, modulos, x, powx;
    char c;
    p_hash = 0;
    s_hash = 0;
    x = 2;
    powx = 1;
    modulos = m*m + 1
    string pattern, substr;
    queue<char> q;
    cin >> m >> n;
    for (ll i = 0; i < m; ++i) {
        cin >> c;
        pattern.push_back(c);
        p_hash = (p_hash + powx*c)%modulos;
        powx *= 2;
    }
    powx = 1;
    for (ll i = 0; i < m; ++i) {
        cin >> c;
        q.push(c);
        substr.push_back(c);
        s_hash = (c_hash + powx*c)%modulos;
        powx *= 2;
    }
    powx /= 2;
    cout << "\nFound pattern at:\n";
    if (substr == pattern) {
        cout << "0 ";
    }
    for (ll i = m; i < n; ++i) {
        cin >> c;
        s_hash -= q.front();
        s_hash /= x;
        s_hash = (s_hash + c*powx)%modulos;
        q.pop();
        q.push(c);
        if (s_hash == p_hash) {
            cout << 
        }
    }
    return 0;
}