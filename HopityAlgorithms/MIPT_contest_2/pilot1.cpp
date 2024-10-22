#include <bits/stdc++.h>


int main()
{
    std::cout << '\n';
    std::vector<int> v = {5, 6, 4, 3, 2, 1, 9, 8, 7, 10};
    std::cout << '{';
    for(int i = 0; i < v.size() - 1; ++i)
        std::cout << v[i] << ", ";
    std::cout << v.back() << '}';
    std::cout << "\n\n";
    std::sort(v.begin(), v.end(), [](const int& a, const int& b){ return a >= b; });
    std::cout << '{';
    for(int i = 0; i < v.size() - 1; ++i)
        std::cout << v[i] << ", ";
    std::cout << v.back() << '}';
    std::cout << "\n\n";
    return 0;
}