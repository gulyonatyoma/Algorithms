#include <bits/stdc++.h>


int main()
{
    long long t, n, m, k, x, y;
    std::cin >> t;
    for(int i = 0; i < t; ++i)
    {
        std::cin >> n >> m >> k;
        bool simple = true;
        bool simple_cycle = true;
        bool none = false;
        std::vector<long long> path;
        std::unordered_map<long long, std::unordered_map<long long, bool>> ht;
        std::unordered_map<long long, std::unordered_map<long long, bool>> ppt;
        std::unordered_map<long long, bool> pt;
        pt.clear();
        ht.clear();
        for(int j = 0; j < k; ++j)
        {
            std::cin >> x;
            if(x > n)
                none = true;
            path.push_back(x);
        }
        for(int j = 0; j < m; ++j)
        {
            std::cin >> x >> y;
            ht[x][y] = true;
            ht[y][x] = true;
        }
        if(k == 0)
        {
            std::cout << "simple path\n";
            break;
        }
        if(k != 0)
            pt[path[0]] = true;
        for(int j = 0; j < k-1; ++j)
        {
            if(ht[path[j]].find(path[j+1]) == ht[path[j]].end())
            {
                none = true;
                break;
            }
            if((j+1 < k-1) && (pt.find(path[j+1]) != pt.end()))
            {
                simple_cycle = false;
                simple = false;
            }
            pt[path[j+1]] = true;
            if(ppt[path[j]].find(path[j+1]) != ppt[path[j]].end())
                simple = false;
            ppt[path[j]][path[j+1]] = true;
            ppt[path[j+1]][path[j]] = true;
        }
        if(none)
            std::cout << "none\n";
        else if((k != 1) && (path[0] == path.back()))
        {
            if(simple_cycle)
                std::cout << "simple ";
            std::cout << "cycle\n";
        }
        else
        {
            if(simple)
                std::cout << "simple ";
            std::cout << "path\n";
        }
    }
    return 0;
}

/*

In:

6

1 0 1
1

3 2 4
1 2 3 1
1 2
2 3

3 3 4
1 2 3 1
1 2
1 3
2 3

5 6 7
1 2 3 5 4 3 1
1 2
1 3
2 3
3 4
3 5
4 5

3 4 5
1 2 3 4 5
1 2
2 3
3 4
4 5

5 5 6
1 2 3 1 4 5
1 2
2 3
3 1
1 4
4 5

Out:

simple path
none
simple cycle
cycle
none
path

*/