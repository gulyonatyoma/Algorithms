#include <bits/stdc++.h>


int main()
{
    std::string temp, str;
    std::cin >> temp >> str;
    std::vector<int> ans;
    std::vector<int> NQM_chars;
    for(int i = temp.size()-1; i >= 0; --i)
        if(temp[i] != '?')
            NQM_chars.push_back(i);
    for(int i = 0; i < (str.size() - temp.size()) + 1; ++i)
    {
        bool flag = true;
        for(int j = 0; j < NQM_chars.size(); ++j)
        {
            if(temp[NQM_chars[j]] != str[NQM_chars[j] + i])
            {
                flag = false;
                break;
            }
        }
        if(flag)
            ans.push_back(i);
    }
    for(const int& index : ans)
        std::cout << index << ' ';
    return 0;
}