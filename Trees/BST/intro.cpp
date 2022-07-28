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
    if (data > root->data)
        root->right = insertIntoBST(root->right, data);
    else
        root->left = insertIntoBST(root->left, data);

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

void levelOrderTraversal(Node *root)
{
    // first we will make a queue :-

    // first first lvl :-
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            cout << '\n';

            // means previous lvl is completed:-
            if (!q.empty())
                q.push(NULL);
        }

        else
        {

            cout << temp->data << " ";

            if (temp->left != NULL)
                q.push(temp->left);
            if (temp->right != NULL)
                q.push(temp->right);
        }
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
void preOrder(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}
void postOrder(Node *root)
{
    if (root == NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

int minValue(Node *root)
{
    Node *temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp->data;
}
int maxValue(Node *root)
{
    Node *temp = root;
    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp->data;
}

int main()
{

    //                          root
    // smaller values than root         Larger values than root

    //               Avg   skew
    // Insertion :- O(h)   O(n)
    // Search :-    O(h)   o(n)
    // Deletion :-
    Node *root = NULL;
    takeIn(root);
    levelOrderTraversal(root);
    cout << '\n';
    cout << "Inorder" << '\n';
    inorderTraversal(root);
    cout << '\n';
    cout << "PreOrder" << '\n';
    preOrder(root);
    cout << '\n';
    cout << "PostOrder" << '\n';
    postOrder(root);

    cout << "MinValue Is " << '\n';
    cout << minValue(root) << '\n';

    cout << "MaxValue Is " << '\n';
    cout << maxValue(root) << '\n';
    return 0;
}
// left -> small.
// right -> big.
// Inorder of BST gives sorted order.