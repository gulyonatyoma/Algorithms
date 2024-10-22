#include <bits/stdc++.h>


int main()
{
    long long t, n, a;
    std::cin >> t;
    for(long long i = 0; i < t; ++i)
    {
        std::vector<std::array<long long, 2>> vs;
        std::vector<std::array<long long, 2>> ans;
        ans.clear();
        vs.clear();
        std::cin >> n;
        for(long long j = 0; j < n; ++j)
        {
            std::cin >> a;
            vs.push_back({j+1, a});
        }
        std::sort(vs.begin(), vs.end(), [](const auto& a, const auto& b){ return a[1] >= b[1]; });
        for(long long j = 0; j < n; ++j)
        {
            for(long long k = j+1; k < j+1+vs[j][1]; ++k)
            {
                --vs[k][1];
                ans.push_back({vs[j][0], vs[k][0]});
            }
        }
        std::cout << ans.size() << '\n';
        for(const auto& t : ans)
        {
            std::cout << t[0] << ' ' << t[1] << '\n';
        }
    }
    return 0;
}