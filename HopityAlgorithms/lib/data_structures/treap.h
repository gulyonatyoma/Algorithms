#pragma once

struct TreapNode
{
    int key, priority;
    TreapNode* left;
    TreapNode* right;
    TreapNode() {}
    // TreapNode(int _key) : key(_key), priority(rand()), left(nullptr), right(nullptr) {}
    TreapNode(int _key, int _priority) : key(_key), priority(_priority), left(nullptr), right(nullptr) {}
};

void TreapSplit (TreapNode* root, int key, TreapNode*& left, TreapNode*& right);
void TreapInsert (TreapNode*& root, TreapNode* node);
int TreapDepth(TreapNode* root);