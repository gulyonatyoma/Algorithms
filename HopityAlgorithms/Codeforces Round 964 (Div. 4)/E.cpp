#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll t, l, r;
    vector<ll> ans;
    cin >> t;
    for (ll i = 0; i < t; ++i)
    {
        cin >> l >> r;
        ll sum = 0;
        ll curr = l;
        while (curr <= r)
        {
            if (curr == l)
            {
                // ll reserve = curr;
                sum += 2 * ceil(log(curr) / log(3));
                // while (curr != 0)
                // {
                //     sum += 2;
                //     curr /= 3;
                // }
                // curr = reserve;
                ++curr;
            }
            else
            {
                // ll reserve = curr;
                // while (curr != 0)
                // {
                //     sum += 1;
                //     curr /= 3;
                // }
                sum += ceil(log(curr) / log(3));
                // curr = reserve;
                ++curr;
            }
        }
        ans.push_back(curr);
    }
    for (const ll &h : ans)
    {
        cout << h << '\n';
    }
    return 0;
}