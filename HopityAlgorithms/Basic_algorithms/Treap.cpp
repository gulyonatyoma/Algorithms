#include <bits/stdc++.h>
using namespace std;
#define ll long long


struct Node {
    ll x;
    ll y;
    Node* l;
    Node* r;
};


void Split(Node* root, ll x, Node*& l, Node*& r) {
    if (root == nullptr) {
        l = nullptr;
        r = nullptr;
    } else if (x < root->x) {
        Split(root->l, x, l, root->l);
        r = root;
    } else {
        Split(root->r, x, root->r, r);
        l = root;
    }
}

void Insert(Node*& root, Node* it) {
    if (root == nullptr) {
        root = it;
    } else if (it->y > root->y) {
        Split(root, it->x, it->l, it->r);
        root = it;
    } else {
        if (it->x < root->x) {
            Insert(root->l, it);
        } else {
            Insert(root->r, it);
        }
    }
}

void Merge(Node*& root, Node* l, Node* r) {
    if (!l || !r) {
        if (!l) {
            root = r;
        } else {
            root = l;
        }
    } else if (l->y > r->y) {
        Merge(l->r, l->r, r);
        root = l;
    } else {
        Merge(r->l, l, r->l);
        root = r;
    }
}

void Erase(Node*& root, ll x) {
    if (root->x == x) {
        Merge(root, root->l, root->r);
    } else {
        if (x < root->x) {
            Erase(root->l, x);
        } else {
            Erase(root->r, x);
        }
    }
}

void InOrderDFS(Node* root, function<void(ll a, ll b)>& func) {
    if (!root)
        return;
    InOrderDFS(root->l, func);
    func(root->x, root->y);
    InOrderDFS(root->r, func);
}

void PrintBFS(Node* root) {
    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
        ll n = q.size();
        for(ll i = 0; i < n; ++i) {
            if (q.front() != nullptr) {
                cout << '(' << q.front()->x << ", " << q.front()->y << ')' << ' ';
                q.push(q.front()->l);
                q.push(q.front()->r);
            }
            q.pop();
        }
        cout << '\n';
    }
}


int main() {
    ll n, x, y;
    Node* root = nullptr;
    cin >> n;
    for (ll i = 0; i < n; ++i) {
        cin >> x >> y;
        Node* new_elem = new Node{x, y, nullptr, nullptr};
        Insert(root, new_elem);
    }
    std::function<void(ll a, ll b)> func = [](ll a, ll b){cout << '(' << a << ", " << b << ") ";};
    cout << "\nIn order depth first search:\n";
    InOrderDFS(root, func);
    cout << "\nBreadth first search:\n";
    PrintBFS(root);
    return 0;
}
