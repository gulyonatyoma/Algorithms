#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll t, n, s, m, l, r;
    cin >> t;
    vector<bool> ans;
    for (ll i = 0; i < t; ++i)
    {
        cin >> n >> s >> m;
        bool ans_flag = false;
        vector<pair<ll, ll>> otrs;
        for (ll j = 0; j < n; ++j)
        {
            cin >> l >> r;
            otrs.push_back({l, r});
        }
        sort(otrs.begin(), otrs.end(), [](const auto &a, const auto &b)
             { return a.first < b.first; });
        ll begin = 0;
        for (ll i = 0; i < n; ++i)
        {
            if (otrs[i].first - begin >= s)
            {
                ans_flag = true;
                break;
            }
            else
            {
                begin = otrs[i].second;
            }
        }
        if (!ans_flag)
        {
            if (m - begin >= s)
            {
                ans_flag = true;
            }
        }
        ans.push_back(ans_flag);
    }
    for (const bool &a : ans)
    {
        if (a)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}