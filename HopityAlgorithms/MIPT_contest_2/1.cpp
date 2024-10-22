#include <bits/stdc++.h>

struct gap
{
    int l;
    int r;
};

int main()
{
    int t;
    std::cin >> t;
    std::vector<gap> v;
    for(int i = 0; i < t; ++i)
    {
        gap temp_gap;
        std::cin >> temp_gap.l >> temp_gap.r;
        v.push_back(temp_gap);
    }
    std::sort(v.begin(), v.end(), [](const gap& g1, const gap& g2)
    {
        if(g1.l == g2.l)
            return g1.r < g2.r;
        return g1.l < g2.l;
    }
    );
    int l = -1;
    int r = 0;
    int result = 0;
    for(int i = 0; i < t; ++i)
    {
        if(l == -1)
        {
            l = v[i].l;
            r = v[i].r;
        }
        else
        {
            if(v[i].r < l)
                continue;
            if(v[i].l < l)
            {
                if(r > v[i].r)
                    l = v[i].r;
                else
                {
                    l = r;
                    r = v[i].r;
                }
            }
            else
            {
                if(v[i].l > r)
                {
                    result += r - l;
                    l = v[i].l;
                    r = v[i].r;
                }
                else
                {
                    result += v[i].l - l;
                    if(v[i].r > r)
                    {
                        l = r;
                        r = v[i].r;
                    }
                    else
                        l = v[i].r;
                }
            }
        }
    }
    result += r - l;
    std::cout << result;
    return 0;
}