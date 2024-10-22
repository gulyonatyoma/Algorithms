#include <bits/stdc++.h>


// might be useful later
/*
bool AreConnected(long long v1, long long v2,
                  std::unordered_map<long long, std::unordered_map<long long, bool>>& ht)
{
    if(ht[v1].find(v2) != ht[v1].end())
        return true;
    else
    {
        bool are_connected = false;
        for(const auto& [v1_next, boolean] : ht[v1])
            are_connected = are_connected || AreConnected(v1_next, v2, ht);
        return are_connected;
    }
}
*/

void Component(long long v,
        std::unordered_map<long long, std::unordered_map<long long, bool>>& ht,
        std::unordered_map<long long, bool>& points,
        std::unordered_map<long long, bool>& included_points)
{
    if(included_points.find(v) != included_points.end())
        return;
    if(points.find(v) == points.end())
    {
        included_points[-1] = true;
        return;
    }
    included_points[v] = true;
    for(const auto& [v_next, boolean] : ht[v])
        Component(v_next, ht, points, included_points);
}

int main()
{
    long long t, n, m, k, x, y;
    std::cin >> t;
    for(int i = 0; i < t; ++i)
    {
        std::cin >> n >> m >> k;
        std::unordered_map<long long, std::unordered_map<long long, bool>> ht;
        std::unordered_map<long long, bool> points;
        std::unordered_map<long long, bool> included_points;
        included_points.clear();
        points.clear();
        ht.clear();
        for(int j = 0; j < k; ++j)
        {
            std::cin >> x;
            points[x] = true;
        }
        for(int j = 0; j < m; ++j)
        {
            std::cin >> x >> y;
            ht[x][y] = true;
            ht[y][x] = true;
        }
        for(const auto& [v, boolean] : points)
            Component(v, ht, points, included_points);
        if(included_points.find(-1) != included_points.end())
            std::cout << "NO\n";
        else
            std::cout << "YES\n";
    }
    return 0;
}