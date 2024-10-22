#include <bits/stdc++.h>

void rng(long long& a, long long& b, long long& m)
{
    if(a + b <= m)
    {
        a += b;
        return;
    }
    a = (a+b)%m;
}


int main()
{
    long long t, n, k;
    std::cin >> t;
    for(long long i = 0; i < t; ++i)
    {
        std::cin >> n >> k;
        if(k < 0)
        {
            std::cout << "NO\n";
            continue;
        }
        if(k == 0)
        {
            if(n < 0)
            {
                std::cout << "NO\n";
                continue;
            }
            std::cout << "YES\n" << 0 << '\n';
            continue;
        }
        else if(k == 1)
        {
            if((n % 2 != 0) || (n <= 0))
            {
                std::cout << "NO\n";
                continue;
            }
            std::cout << "YES\n";
            std::cout << n/2 << '\n';
            for(long long j = 1; j <= n; j += 2)
                std::cout << j << ' ' << j+1 << '\n';
        }
        else
        {
            long long num_of_edges = 0;
            std::vector<std::pair<long long, long long>> ans;
            ans.clear();
            if(k > n-1)
            {
                std::cout << "NO\n";
                continue;
            }
            else if(k % 2 == 0)
            {
                std::cout << "YES\n";
                for(long long j = 1; j <= k/2; ++j)
                {
                    long long sup_cv = 1;
                    long long edges = 0;
                    while(edges < n)
                    {
                        long long cv = sup_cv;
                        long long iterations = 0;
                        do
                        {
                            std::pair<long long, long long> pr;
                            pr.first = cv;
                            rng(cv, j, n);
                            if((iterations == 1) && (cv == sup_cv))
                                break;
                            ++edges;
                            ++num_of_edges;
                            ++iterations;
                            pr.second = cv;
                            ans.push_back(pr);
                        }while(cv != sup_cv);
                        ++sup_cv;
                    }
                }
            }
            else
            {
                if(n % 2 == 1)
                {
                    std::cout << "NO\n";
                    continue;
                }
                std::cout << "YES\n";
                for(long long j = 1; j <= k/2; ++j)
                {
                    long long sup_cv = 1;
                    long long edges = 0;
                    while(edges < n)
                    {
                        long long cv = sup_cv;
                        do
                        {
                            std::pair<long long, long long> pr;
                            pr.first = cv;
                            rng(cv, j, n);
                            ++edges;
                            ++num_of_edges;
                            pr.second = cv;
                            ans.push_back(pr);
                        }while(cv != sup_cv);
                        ++sup_cv;
                    }
                }
                for(long long j = 1; j <= n/2; ++j)
                    ans.push_back({j, j + n/2});
                num_of_edges += n/2;
            }
            if(!ans.empty())
            {
                std::cout << num_of_edges << '\n';
                for(const auto& pr : ans)
                    std::cout << pr.first << ' ' << pr.second << '\n';
            }
        }
    }
    return 0;
}