#include <bits/stdc++.h>


int main()
{
    long long t, n, m, x, y;
    std::cin >> t;
    for(int i = 0; i < t; ++i)
    {
        bool wrong_flag = false;
        std::cin >> n >> m;
        std::unordered_map<long long, std::unordered_map<long long, bool>> ht;
        ht.clear();
        for(int j = 0; j < m; ++j)
        {
            std::cin >> x >> y;
            if(x == y)
                wrong_flag = true;
            if((ht[x].find(y) != ht[x].end()) || (ht[y].find(x) != ht[y].end()))
                wrong_flag = true;
            ht[x][y] = true;
        }
        if(wrong_flag)
            std::cout << "NO\n";
        else
            std::cout << "YES\n";
    }
    return 0;
}