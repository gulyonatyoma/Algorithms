#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll t, a1, a2, b1, b2, A, B, A_wins, B_wins;
    vector<ll> ans;
    cin >> t;
    for (ll i = 0; i < t; ++i)
    {
        cin >> a1 >> a2 >> b1 >> b2;
        A = B = A_wins = B_wins = 0;
        if (a1 > b1)
            ++A;
        else if (a1 < b1)
            ++B;
        if (a2 > b2)
            ++A;
        else if (a2 < b2)
            ++B;
        if (A > B)
            ++A_wins;
        else if (A < B)
            ++B_wins;
        A = B = 0;
        if (a1 < b2)
            ++A;
        else if (a1 < b2)
            ++B;
        if (a2 < b1)
            ++A;
        else if (a2 < b1)
            ++B;

        return 0;
    }
}