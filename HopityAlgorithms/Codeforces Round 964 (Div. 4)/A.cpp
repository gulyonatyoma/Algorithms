#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll t, n;
    vector<ll> ans;
    cin >> t;
    for (ll i = 0; i < t; ++i)
    {
        cin >> n;
        ll sum = 0;
        while (n != 0)
        {
            sum += n % 10;
            n /= 10;
        }
        ans.push_back(sum);
    }
    for (const ll &a : ans)
    {
        cout << a << '\n';
    }
    return 0;
}