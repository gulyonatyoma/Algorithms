#include <bits/stdc++.h>
#include "../lib/data_structures/treap.h"
#include "../lib/data_structures/naive_tree.h"

// struct TreeNode
// {
//     TreeNode() : left{nullptr}, val{0}, right{nullptr} {}
//     TreeNode(std::pair<int, int> val_) : left{nullptr}, val{val_}, right{nullptr} {}
//     void AddLeftNode(std::pair<int, int> val_)
//     {
//         TreeNode* new_node = new TreeNode(val_);
//         left = new_node;
//     }
//     void AddRightNode(std::pair<int, int> val_)
//     {
//         TreeNode* new_node = new TreeNode(val_);
//         right = new_node;
//     }
//     TreeNode* left;
//     TreeNode* right;
//     std::pair<int, int> val;
// };


// class Treap
// {
//     public:
//         Treap() : root{nullptr} {}
//         void AddNode(int x, int y)
//         {
//             if(root == nullptr)
//             {
//                 root = new TreeNode({x, y});
//                 return;
//             }
//             TreeNode* curr = root;
//             for(;;)
//             {
//                 if(y > curr->val.second)
//                 {
//                     TreeNode* new_node = new TreeNode({x, y});
//                     if(x > curr->val.first)
//                     {
//                         new_node->right = curr->right;
//                         new_node->left = 
//                     }
//                     else
//                     {

//                     }
//                 }
//                 else
//                 {
//                     if(x > curr->val.first)
//                     {

//                     }
//                     else
//                     {

//                     }
//                 }
//             }
//         }
//     private:
//         TreeNode* root;
// };


int main()
{
    int N, x, y;
    TreapNode* treap = nullptr;
    NaiveTreeNode* naive_tree = nullptr;
    std::cin >> N;
    for(int i = 0; i < N; ++i)
    {
        std::cin >> x >> y;
        TreapNode* treap_node = new TreapNode(x, y);
        TreapInsert(treap, treap_node);
        AddKey(naive_tree, x);
    }
    std::cout << NaiveTreeDepth(naive_tree) - TreapDepth(treap);
    return 0;
}

// g++ -Og -g -Wall -Wextra -pedantic -Ilib MIPT_contest_2/2.cpp lib/data_structures/naive_tree.cpp lib/data_structures/treap.cpp -o bin/2.exe