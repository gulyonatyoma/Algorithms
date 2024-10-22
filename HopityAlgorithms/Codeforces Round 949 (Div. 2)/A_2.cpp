#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using std::cin;
using std::cout;

int main()
{
    std::vector<int> ans;
    int t, l, r;
    cin >> t;
    for(int i = 0; i < t ; ++i)
    {
        cin >> l >> r;
        int curr = 2;
        int sum = 0;
        while((curr < l) || (curr <= r))
        {
            ++sum;
            curr *= 2;
        }
        ans.push_back(sum);
    }
    for(const int& i : ans)
        std::cout << i << '\n';
}