#pragma once

struct NaiveTreeNode
{
    NaiveTreeNode() : val{}, left{nullptr}, right{nullptr} {}
    NaiveTreeNode(int _val) : val{_val}, left{nullptr}, right{nullptr} {}
    void AddLeftNode(int _val);
    void AddRightNode(int _val);
    int val;
    NaiveTreeNode* left;
    NaiveTreeNode* right;
};

void AddKey(NaiveTreeNode*& root, int key);
int NaiveTreeDepth(NaiveTreeNode* root);
void PostOrderRecursiveDFS(NaiveTreeNode* root);
void PostOrderIterativeDFS(NaiveTreeNode* root);