#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve()
{
    int n, s, m;
    cin >> n >> s >> m;
    vector<pair<int, int>> times;
    while (n--)
    {
        int a, b;
        cin >> a >> b;
        times.push_back({a, b});
    }
    sort(times.begin(), times.end(), [](auto f, auto s)
         { return f.first < s.first; });
    int save = times[0].second;
    bool break_flag = false;
    for (int i = 1; i < times.size(); i++)
    {
        int save2 = times[i].first;
        if ((save2 - save) >= s)
        {
            cout << "YES";
            break_flag = true;
            break;
        }
        save = times[i].second;
    }
    if (break_flag)
    {
        if ((m - times[times.size() - 1].second) >= s)
        {
            cout << "YES";
        }
        else
        {
            cout << "NO";
        }
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("in.txt",

    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
        cout << '\n';
    }
    return 0;
}
