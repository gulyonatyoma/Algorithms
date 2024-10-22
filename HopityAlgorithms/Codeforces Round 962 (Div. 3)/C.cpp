#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {
    ll N;
    ll n, q, amount;
    ll l, r;
    vector<ll> ans;
    char c;
    vector<ll> a(26);
    vector<ll> b(26);
    vector<vector<ll>> a_pr;
    vector<vector<ll>> b_pr;
    vector<ll> a_otr;
    vector<ll> b_otr;
    vector<ll> temp;
    cin >> N;
    for (ll i = 0; i < N; ++i) {
        cin >> n >> q;
        for(ll j = 0; j < 26; ++j) {
            a[j] = 0;
            b[j] = 0;
        }
        a_pr.clear();
        b_pr.clear();
        for (ll j = 0; j < n; ++j) {
            cin >> c;
            ++a[c-'a'];
            a_pr.push_back(a);
        }
        for (ll j = 0; j < n; ++j) {
            cin >> c;
            ++b[c-'a'];
            b_pr.push_back(b);
        }
        for (ll k = 0; k < q; ++k) {
            cin >> l >> r;
            a_otr.clear();
            b_otr.clear();
            temp.clear();
            a_otr = a_pr[r-1];
            b_otr = b_pr[r-1];
            if (l > 1) {
                temp = a_pr[l-2];
                for (ll j = 0; j < 26; ++j) {
                    a_otr[j] -= temp[j];
                }
                temp = b_pr[l-2];
                for (ll j = 0; j < 26; ++j) {
                    b_otr[j] -= temp[j];
                }
            }
            amount = 0;
            for (ll j = 0; j < 26; ++j) {
                if (b_otr[j] > a_otr[j]) {
                    amount += b_otr[j] - a_otr[j];
                }
            }
            ans.push_back(amount);
            // for (ll j = l - 1; j < r; ++j) {
            //     a_otr = a_pr
            // }
            // for (ll j = 0; j < 26; ++j) {
            //     amount += b[j] - a[j];
            // }
            // ans.push_back(amount);
        }
    }
    for(const auto& l : ans) {
        cout << l << '\n';
    }
    return 0;
}