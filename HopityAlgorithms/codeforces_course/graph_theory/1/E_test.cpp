#include <bits/stdc++.h>
 
 
int main()
{
    // long long t, n, x;
    // std::cin >> t;
    // for(long long i = 0; i < t; ++i)
    // {
    //     std::cin >> n;
    //     bool tree_flag = true;
    //     bool root_flag = true;
    //     if(n == 1)
    //     {
    //         std::cin >> x;
    //         if(x == 0)
    //             std::cout << "YES\n";
    //         continue;
    //     }
    //     long long supposed_1s = 0;
    //     long long actual_1s = 0;
    //     for(long long j = 0; j < n; ++j)
    //     {
    //         std::cin >> x;
    //         if(x <= 0)
    //             tree_flag = false;
    //         if(root_flag)
    //         {
    //             x += 2;
    //             root_flag = false;
    //         }
    //         if(x > 1)
    //             supposed_1s += x-2;
    //         else
    //             ++actual_1s;
    //     }
    //     if(actual_1s != supposed_1s)
    //         tree_flag = false;
    //     if(tree_flag)
    //         std::cout << "YES\n";
    //     else
    //         std::cout << "NO\n";
    // }
    // return 0;
 
 
    long long t, n, x;
    std::cin >> t;
    for(long long i = 0; i < t; ++i)
    {
        std::cin >> n;
        long long sum = 0;
        long long leaves = 0;
        for(long long j = 0; j < n; ++j)
        {
            std::cin >> x;
            if(((x == 0) && (n == 1)) || ((x == 1) && (n > 1)))
                ++leaves;
            sum += x;
        }
        if((sum == (2*n - 2)) && (leaves >= 1))
            std::cout << "YES\n";
        else
            std::cout << "NO\n";
    }
    return 0;
 
 
    // long long t, n, x;
    // std::cin >> t;
    // for(long long i = 0; i < t; ++i)
    // {
    //     std::cin >> n;
    //     if(n == 0)
    //     {
    //         std::cout << "NO\n";
    //         continue;
    //     }
    //     else if(n == 1)
    //     {
    //         std::cin >> x;
    //         if(x == 0)
    //             std::cout << "YES\n";
    //         continue;
    //     }
    //     bool tree_flag = true;
    //     long long sum = 0;
    //     long long supposed_1s = 2;
    //     long long actual_1s = 0;
    //     for(long long j = 0; j < n; ++j)
    //     {
    //         std::cin >> x;
    //         // if(x <= 0)
    //         //     tree_flag = false;
    //         if(x == 1)
    //             ++actual_1s;
    //         else
    //             supposed_1s += (x - 2);
    //         sum += x;
    //     }
    //     // if(supposed_1s != actual_1s)
    //     //     tree_flag = false;
    //     if(sum != (2*n - 2))
    //         tree_flag = false;
    //     if(tree_flag)
    //         std::cout << "YES\n";
    //     else
    //         std::cout << "NO\n";
    // }
}