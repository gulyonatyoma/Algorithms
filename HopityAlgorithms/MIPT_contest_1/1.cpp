#include <bits/stdc++.h>
#include "../lib/data_structures/naive_tree.h"


int main()
{
    int N, key;
    NaiveTreeNode* naive_tree = nullptr;
    std::cin >> N;
    for(int i = 0; i < N; ++i)
    {
        std::cin >> key;
        AddKey(naive_tree, key);
    }
    PostOrderIterativeDFS(naive_tree);
    return 0;
}

// g++ -Og -g -Wall -Wextra -pedantic -Ilib MIPT_contest_1/1.cpp lib/data_structures/naive_tree.cpp -o bin/1_1.exe