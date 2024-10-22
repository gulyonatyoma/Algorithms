#include <bits/stdc++.h>
#define ll long long

// Happy ignorance

constexpr ll m = std::pow(2, 63);
constexpr ll p = 2;

// ll hash(std::string str)
// {

// }

int main()
{
    std::string temp, str;
    // std::hash<std::string> hasher;
    std::cin >> temp >> str;
    std::vector<std::array<int, 2>> indices_vector;
    bool q_flag = true;
    bool change_flag = false;
    for(int i = 0; i < temp.size(); ++i)
    {
        if(temp[i] == '?' && !q_flag)
        {
            change_flag = true;
            q_flag = true;
        }
        if(temp[i] != '?' && q_flag)
        {
            change_flag = true;
            q_flag = false;
        }
        if(change_flag && !q_flag)
            indices_vector.push_back({i, -1});
        else if(change_flag && q_flag)
            indices_vector.back()[1] = i;
    }
    if(!q_flag)
        indices_vector.back()[1] = temp.size();
    std::vector<ll> str_hash_vector;
    for(int i = 0; i < str.size(); ++i)
    {
        if(i == 0)
            str_hash_vector[i] = str[i]%m;
        else
            str_hash_vector[i] = (str_hash_vector[i-1]*p + str[i])%m;
    }
    std::vector<ll> temp_hash_vector;
    for(int i = 0; i < indices_vector.size(); ++i)
    {
        ll hsh = 0;
        for(int j = indices_vector[i][0]; j < indices_vector[i][1]; ++j)
        {
            if(j - indices_vector[i][0] == 0)
                hsh = temp[j]%m;
            else
                hsh = (hsh*p + temp[j])%m;
        }
        temp_hash_vector.push_back(hsh);
    }
    for(int i = 0; i < str.size() - temp.size() + 1; ++i)
    {
    }
    return 0;
}