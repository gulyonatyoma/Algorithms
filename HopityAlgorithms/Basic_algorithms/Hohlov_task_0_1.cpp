#include <iostream>
#include <unordered_map>
#include <string>
#define ll long long
using namespace std;

void parse(unordered_map<string, unordered_map<string, bool>> &graph)
{
    string tstr, str;
    while (cin)
    {
        getline(cin, str);
        if (str.empty())
            break;
        tstr.clear();
        int i = 0;
        while (str[i] != ':')
        {
            tstr.push_back(str[i]);
            ++i;
        }
        i += 3;
        string vert = tstr;
        tstr.clear();
        while (i < str.size() - 1)
        {
            if (str[i] != ',')
            {
                tstr.push_back(str[i]);
                ++i;
            }
            else
            {
                graph[tstr][vert] = true;
                tstr.clear();
                i += 2;
            }
        }
        graph[tstr][vert] = true;
    }
}

void print(unordered_map<string, unordered_map<string, bool>> &graph)
{
    for (const auto &[key, value] : graph)
    {
        cout << key << ": ";
        for (const auto [key2, value2] : graph[key])
        {
            cout << key2 << ", ";
        }
        cout << '\n';
    }
}

int main()
{
    // std::string str;
    // std::getline(std::cin, str);
    // string tstr, str;
    unordered_map<string, unordered_map<string, bool>> graph;
    parse(graph);
    print(graph);
    return 0;
}