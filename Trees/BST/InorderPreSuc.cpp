#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    Node *left;
    Node *right;
    int data;

    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *insertIntoBST(Node *&root, int data)
{
    if (root == NULL)
    {
        root = new Node(data);
        return root;
    }

    if (data < root->data)
        root->left = insertIntoBST(root->left, data);
    else
        root->right = insertIntoBST(root->right, data);

    return root;
}
void takeInput(Node *&root)
{
    int data;
    cin >> data;
    while (data != -1)
    {
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

void inorderTraversal(Node *root)
{
    if (root == NULL)
        return;
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

void InorderPredecessor(Node *root)
{
}
int main()
{
    Node *root = NULL;
    takeInput(root);
    inorderTraversal(root);

    return 0;
}