#include <bits/stdc++.h>

int main()
{
    long long t, m;
    std::vector<long long> ans;
    std::cin >> t;
    for(long long i = 0; i < t; ++i)
    {
        std::cin >> m;
        ans.push_back(std::ceil((1+std::sqrt(1+8*m))/2));
    }
    for(const long long& num : ans)
        std::cout << num << '\n';
    return 0;
}