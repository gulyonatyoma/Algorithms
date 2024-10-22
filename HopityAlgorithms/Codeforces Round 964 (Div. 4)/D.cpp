#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll T;
    string s, t;
    cin >> T;
    for (ll i = 0; i < T; ++i)
    {
        cin >> s >> t;
        vector<char> sv;
        for (const char &c : s)
        {
            sv.push_back(c);
        }
        ll sptr = 0;
        ll tptr = 0;
        while ((sptr != s.size()) && tptr != t.size())
        {
            if (s[sptr] != '?')
            {
                if (s[sptr] == t[tptr])
                {
                    ++sptr;
                    ++tptr;
                    continue;
                }
                else
                {
                    ++sptr;
                    continue;
                }
            }
            else
            {
                sv[sptr] = t[tptr];
                ++sptr;
                ++tptr;
                continue;
            }
        }
        if (tptr == t.size())
        {
            cout << "YES\n";
            for (ll i = 0; i < s.size(); ++i)
            {
                if (sv[i] != '?')
                    cout << sv[i];
                else
                    cout << 'x';
            }
            cout << '\n';
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}