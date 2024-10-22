#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using std::cin;
using std::cout;

int FindSum(int number)
{
    int sum = 0;
    while(number != 1)
    {
        bool flag = true;
        for(int i = 2; i <= int(std::pow(number, 0.5)) + 1; ++i)
        {
            if(number%i == 0)
            {
                ++sum;
                number /= i;
                flag = false;
                break;
            }
        }
        if(flag)
        {
            number /= number;
            ++sum;
        }
    }
    return sum;
}

int main()
{
    std::vector<int> ans;
    int t, l, r, max;
    cin >> t;
    for(int i = 0; i < t ; ++i)
    {
        cin >> l >> r;
        max = 0;
        for(int j = l; j <= r; ++j)
            max = std::max(max, FindSum(j));
        ans.push_back(max);
    }
    for(const int& i : ans)
        std::cout << i << '\n';
}