#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using std::cin;
using std::cout;

int main()
{
    std::vector<std::vector<long long>> ans;
    long long t, n, temp;
    cin >> t;
    for(int i = 0; i < t; ++i)
    {
        bool flag = false;
        cin >> n;
        std::vector<std::pair<long long, long long>> numbers;
        long long curr = 0;
        for(int j = 0; j < n; ++j)
        {
            cin >> temp;
            if(temp == -1)
                ++curr;
            else
            {
                if(!numbers.empty())
                {
                    if
                    (
                    (temp != 2*numbers.back()) ||
                    (temp != (2*numbers.back() + 1)) ||
                    (temp != (numbers.back() / 2))
                    )
                    {
                        flag = true;
                        break;
                    }
                }
                numbers.push_back({temp, curr});
                curr = 0;
            }
        }
    }
    return 0;
}