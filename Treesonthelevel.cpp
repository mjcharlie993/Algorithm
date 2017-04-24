#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
const int maxn = 256;
char s[maxn];
bool failed = false;

struct Node {
    int val;
    bool have_value;
    Node *left, *right;
    Node() : have_value(false), left(nullptr), right(nullptr) {}
};

Node* root;
bool failed = false;

Node* newnode() {
    return new Node();
}

void addnode(int val, char* s) {
    int n = strlen(s);
    Node* u = root;
    for (int i = 0; i != n; i++)
        if (s[i] == 'L') {
            if (u->left == nullptr)
                u->left = newnode();
            u = u->left;
        }else if (s[i] == 'R') {
            if (u->right == nullptr)
                u->right = newnode();
            u = u->right;
        }
    if (u->have_value) 
        failed = true;
    u->val = val;
    u->have_value = true;
}

void remove_tree(Node* u) {
    if (u == nullptr)
        return;
    remove_tree(u->left);
    remove_tree(u->right);
    delete u;
}

bool bfs(vector<int>& ans) {
    queue<Node*> q;
    ans.clear();
    q.push(root);
    while (!q.empty()) {
        Node* u = q.front();
        q.pop();
        if (u->have_value)
            return false;
        ans.push_back(u->val);
        if (u->left)
            q.push(u->left);
        if (u->right)
            q.push(u->right);
    }
    return true;
}

bool read_input() {
    failed = false;
    root = newnode();
    for (;;) {
        if (scanf("%s", s) != 1)
            return false;
        if (!strcmp(s,"()"))
            break;
        int v;
        sscanf(&s[1], "%d", v);
        addnode(v, strchr(s, ',') + 1);
    }
    return true;
}