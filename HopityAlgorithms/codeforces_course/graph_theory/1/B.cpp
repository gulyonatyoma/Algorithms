#include <bits/stdc++.h>


int main()
{
    long long t, n, m, x, y;
    std::cin >> t;
    for(int i = 0; i < t; ++i)
    {
        std::cin >> n >> m;
        std::unordered_map<long long, long long> ht;
        ht.clear();
        for(int j = 0; j < m; ++j)
        {
            std::cin >> x >> y;
            if(ht.find(x) != nullptr)
                ++ht[x];
            else
                ht[x] = 1;
            if(ht.find(y) != nullptr)
                ++ht[y];
            else
                ht[y] = 1;
        }
        for(int i = 1; i <= n; ++i)
        {
            if(ht.find(i) == nullptr)
                std::cout << 0 << ' ';
            else
                std::cout << ht[i] << ' ';
        }
        std::cout << '\n';
    }
    return 0;
}