#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {
    ll N, n, k;
    char c;
    vector<vector<char>> ans;
    cin >> N;
    for(ll i = 0; i < N; ++i) {
        cin >> n >> k;
        for(ll j = 0; j < n/k; ++j) {
            for(ll l = 0; l < k; ++l) {
                if (l == 0) {
                    ans.push_back({});
                    for (ll p = 0; p < n/k; ++p) {
                        for (ll m = 0; m < k; ++m) {
                            cin >> c;
                            if (m == 0)
                                ans.back().push_back(c);
                        }
                    }
                } else {
                    for (ll p = 0; p < n/k; ++p) {
                        for (ll m = 0; m < k; ++m) {
                            cin >> c;
                        }
                    }
                }
            }
        }
    }
    for (const auto& v : ans) {
        for (const auto& c : v) {
            cout << c;
        }
        cout << '\n';
    }
    return 0;
}