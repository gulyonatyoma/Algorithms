#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {
    ll N, n, k;
    char t;
    vector<vector<char>> ans;
    cin >> N;
    for (ll a = 0; a < N; ++a) {
        for (ll i = 0; i < N; ++i) {
            cin >> n >> k;
            bool is_first_1 = true;
            for(ll iter = 0; iter < n/k; ++iter) {
                for(ll j = 0; j < n/k; ++j) {
                    if(is_first_1) {
                        is_first_1 = false;
                        ans.push_back({});
                        bool is_first_2 = true;
                        for(ll l = 0; l < k; ++l) {
                            cin >> t;
                            if (is_first_2) {
                                // cout << t;
                                ans.back().push_back(t);
                                is_first_2 = false;
                            }
                        }
                    }
                    else {
                        for (ll l = 0; l < k; ++l) {
                            cin >> t;
                        }
                    }
                }
            }
        }
    }
    for (const auto& v : ans) {
        for (const auto& l : v) {
            cout << l;
        }
        cout << '\n';
    }
    return 0;
}