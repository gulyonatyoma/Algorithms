#include <bits/stdc++.h>
using namespace std;
#define ll long long


struct triple {
    ll a;
    ll b;
    ll c;
};


int main() {
    ll t, n, x, amount;
    vector<ll> answer;
    // unordered_map<triple, bool> mp;
    cin >> t;
    for (ll i = 0; i < t; ++i) {
        cin >> n >> x;
        amount = 0;
        ll numbah = ceil(sqrt(x*x - 2*n));
        for (ll a = 1; a < numbah; ++a) {
            for (ll b = 1; b < numbah; ++b) {
                for (ll c = 1; c < numbah; ++c) {
                    if (a*a + b*b + c*c <= x*x - 2*n) {
                        // if ((a == b) && (b == c)) {
                        //     ++amount;
                        //     // mp[{a, b, c}] = true;
                        // } else if ((a == b) && (b != c)) {
                        //     amount += 3;
                        //     // mp[{a, b, c}] = true;
                        // } else if (())
                        ++amount;
                    }
                }
            }
        }
        answer.push_back(amount);
    }
    for (const ll& ans : answer) {
        cout << ans << '\n';
    }
    return 0;
}