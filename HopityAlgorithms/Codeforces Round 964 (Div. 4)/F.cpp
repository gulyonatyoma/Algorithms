#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll icomb(ll n, ll k, ll mod)
{
    vector<ll> not_included;
    vector<ll> n_minus_k;
    for (ll i = 1; i <= n - k; ++i)
    {
        n_minus_k.push_back(i);
    }
    ll ptr = 0;
    ll ans = 1;
    for (ll i = n; i <= n - k + 1; ++i)
    {
        if (i % n_minus_k[ptr])
        {
            ans = (ans * (i / n_minus_k[ptr])) % mod;
            ++ptr;
        }
        else
        {
            not_included.push_back(i);
        }
    }
    for (const auto &a : not_included)
    {
        ans = (ans * a) % mod;
    }
    return ans;
}

int main()
{
    ll t, n, k, num;
    vector<ll> ans;
    cin >> t;
    for (ll i = 0; i < t; ++i)
    {
        cin >> n >> k;
        ll count1 = 0;
        ll count0 = 0;
        for (ll j = 0; j < n; ++j)
        {
            cin >> num;
            if (num)
                ++count1;
            else
                ++count0;
        }
    }
    return 0;
}