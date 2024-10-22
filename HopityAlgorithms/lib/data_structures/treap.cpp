#include "treap.h"
#include <algorithm>

void TreapSplit (TreapNode* root, int key, TreapNode*& left, TreapNode*& right)
{
    if(!root)
        left = right = nullptr;
    else if(root->key <= key)
    {
        left = root;
        TreapSplit(root->right, key, root->right, right);
    }
    else
    {
        right = root;
        TreapSplit(root->left, key, left, root->left);
    }
}

void TreapInsert (TreapNode*& root, TreapNode* node)
{
    if (!root)
        root = node;
    else if (node->priority > root->priority)
        TreapSplit (root, node->key, node->left, node->right),  root = node;
    else
        TreapInsert (root->key <= node->key ? root->right : root->left, node);
}

int TreapDepth(TreapNode* root)
{
    if(!root)
        return 0;

    int left_depth = TreapDepth(root->left);
    int right_depth = TreapDepth(root->right);
    return 1 + std::max(left_depth, right_depth);
}

void TreapMerge(TreapNode*& root, TreapNode* left, TreapNode* right)
{
    if (!left || !right)
        root = left ? left : right;
    else if (left->priority > right->priority)
    {
        root = left;
        TreapMerge(left->right, left->right, right)
    }
    else
    {
        root = right;
        TreapMerge(right->left, left, right->left)
    }
}

void TreapErase(TreapNode*& root, int key)
{
    if (root->key == key)
    {
        TreapNode* th = root;
        TreapMerge(root, root->left, root->right);
        delete th;
    }
    else
        erase (key < root->key ? root->left : root->right, key);
}