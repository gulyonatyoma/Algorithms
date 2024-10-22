#include <bits/stdc++.h>
using namespace std;
#define ll long long


ll fl (ll n) {
    if (n == 1) {
        return 0;
    } else {
        return fl(n/2) + 1;
    }
}


class SparseTable {
    public:
        SparseTable(vector<ll>& arr);
        void Print();
        ll Min(ll l, ll r) {
            if (l == r) {
                return st[l][0];
            }
            ll& j = fls[r-l];
            return min(st[l][j], st[r - pow2[j] + 1][j]);
        }
    private:
        vector<vector<ll>> st;
        vector<ll> fls;
        vector<ll> pow2;
};


SparseTable::SparseTable(vector<ll>& arr) {
    ll N = arr.size();
    ll k = 1;
    fls.push_back(-1);
    for (ll j = 0; j <= fl(N); ++j) {
        pow2.push_back(k);
        if (j == 0) {
            for (ll i = 0; i < N; ++i) {
                fls.push_back(fl(i+1));
                st.push_back({arr[i]});
            }
        } else {
            deque<ll> dq;
            ll l = 0;
            ll r = 0;
            while (r < N) {
                while ((!dq.empty()) && (arr[dq.back()] > arr[r])) {
                    dq.pop_back();
                }
                dq.push_back(r);
                if (l > dq.front()) {
                    dq.pop_front();
                }
                if ((r+1) >= k) {
                    st[l].push_back(arr[dq.front()]);
                    ++l;
                }
                ++r;
            }
        }
        k *= 2;
    }
}


void SparseTable::Print() {
    cout << "SparseTable.Print():\n";
    for (ll i = 0; i < st.size(); ++i) {
        for (ll j = 0; j < st[i].size(); ++j) {
            cout << st[i][j] << ' ';
        }
        cout << '\n';
    }
}


int main() {
    ll n, m, l, r;
    vector<ll> arr;
    vector<ll> ans;
    cin >> n;
    for (ll i = 0; i < n; ++i) {
        cin >> l;
        arr.push_back(l);
    }
    SparseTable st{arr};
    st.Print();
    cin >> m;
    for (ll i = 0; i < m; ++i) {
        cin >> l >> r;
        ans.push_back(st.Min(l, r));
    }
    for (const ll& a : ans) {
        cout << a << '\n';
    }
    return 0;
}