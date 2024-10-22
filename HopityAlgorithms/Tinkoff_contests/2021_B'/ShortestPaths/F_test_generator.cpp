#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {
    ll n, s, t;
    cin >> n >> s >> t;
    cout << n << ' ' << s << ' ' << t << '\n';
    for(ll i = 0; i < n; ++i) {
        for(ll j = 0; j < n; ++j) {
            cout << ((rand()%3 == 0) ? -1 : rand()%n) << ' ';
        }
        cout << '\n';
    }
    return 0;
}