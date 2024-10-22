#include "naive_tree.h"
#include <algorithm>
#include <iostream>
#include <stack>

void NaiveTreeNode::AddLeftNode(int _val)
{
    NaiveTreeNode* new_node = new NaiveTreeNode(_val);
    left = new_node;
}

void NaiveTreeNode::AddRightNode(int _val)
{
    NaiveTreeNode* new_node = new NaiveTreeNode(_val);
    right = new_node;
}

void AddKey(NaiveTreeNode*& root, int key)
{
    if(!root)
    {
        root = new NaiveTreeNode(key);
        return;
    }
    NaiveTreeNode* curr = root;
    for(;;)
    {
        if(key < curr->val)
        {
            if(curr->left == nullptr)
            {
                curr->AddLeftNode(key);
                return;
            }
            curr = curr->left;
        }
        else
        {
            if(curr->right == nullptr)
            {
                curr->AddRightNode(key);
                return;
            }
            curr = curr->right;
        }
    }
}

int NaiveTreeDepth(NaiveTreeNode* root)
{
    if(!root)
        return 0;

    int left_depth = NaiveTreeDepth(root->left);
    int right_depth = NaiveTreeDepth(root->right);
    return 1 + std::max(left_depth, right_depth);
}

void PostOrderRecursiveDFS(NaiveTreeNode* root)
{
    if(!root)
        return;
    PostOrderRecursiveDFS(root->left);
    PostOrderRecursiveDFS(root->right);
    std::cout << root->val << ' ';
}

void PostOrderIterativeDFS(NaiveTreeNode* root)
{
    std::stack<NaiveTreeNode*> iteration_stack;
    std::stack<int> values_stack;
    iteration_stack.push(root);
    while(!iteration_stack.empty())
    {
        NaiveTreeNode* current_node = iteration_stack.top();
        iteration_stack.pop();
        if(current_node != nullptr)
        {
            iteration_stack.push(current_node->left);
            iteration_stack.push(current_node->right);
            values_stack.push(current_node->val);
        }
    }
    while(!values_stack.empty())
    {
        std::cout << values_stack.top() << ' ';
        values_stack.pop();
    }
}