#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        this->data = d;
        left = NULL;
        right = NULL;
    }
};

Node *buildTree(Node *&root)
{

    cout << "Enter Data " << '\n';
    int d;
    cin >> d;

    root = new Node(d);
    if (d == -1)
        return NULL;

    cout << "Enter data for left Node " << d << '\n';
    root->left = buildTree(root->left);

    cout << "Enter data for right Node" << d << '\n';
    root->right = buildTree(root->right);

    return root;
}

void inorderTraversal(Node *root)
{
    if (root == NULL)
        return;
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

vector<int> morrisTraversal(Node *root)
{
    // INORDER
    Node *cur = root;
    vector<int> inorder;
    while (cur != NULL)
    {

        if (cur->left == NULL)
        {
            // as if there is no left that means our current node is root node
            //  we will add it to our ans and will move to right part.
            inorder.push_back(cur->data);
            cur = cur->right;
        }
        else
        {

            // if left part exist
            // then we will move to its left's rightmost element
            Node *prev = cur->left;
            while (prev->right != NULL && prev->right != cur)
            {
                prev = prev->right;
            }

            // now 2 cases are possible
            // either prev is NULL (Means there is no threading)
            if (prev->right == NULL)
            {
                prev->right = cur;
                // and we will move our current node
                cur = cur->left;
            }
            else
            {
                // there already present a link
                // means we have already created a link now we will remove it
                // and will store our ans
                prev->right = NULL;
                inorder.push_back(cur->data);
                cur = cur->right;
            }
        }
    }

    return inorder;
}

vector<int> morrisTraversalPreOrder(Node *root)
{
    // PReORDEr
    Node *cur = root;
    vector<int> preorder;
    while (cur != NULL)
    {

        if (cur->left == NULL)
        {
            // as if there is no left that means our current node is root node
            //  we will add it to our ans and will move to right part.
            preorder.push_back(cur->data);
            cur = cur->right;
        }
        else
        {

            // if left part exist
            // then we will move to its left's rightmost element
            Node *prev = cur->left;
            while (prev->right != NULL && prev->right != cur)
            {
                prev = prev->right;
            }

            // now 2 cases are possible
            // either prev is NULL (Means there is no threading)
            if (prev->right == NULL)
            {
                prev->right = cur;
                preorder.push_back(cur->data);
                // and we will move our current node
                cur = cur->left;
            }
            else
            {
                // there already present a link
                // means we have already created a link now we will remove it
                // and will store our ans
                prev->right = NULL;
                cur = cur->right;
            }
        }
    }

    return preorder;
}

int main()
{
    Node *root = NULL;
    buildTree(root);
    inorderTraversal(root);
    cout << '\n';
    // Morris Traversal :- INORDER
    //  Left Root Right
    // 1 3 7 -1 -1 11 -1 -1  5 17 -1 -1 -1
    vector<int> inorder = morrisTraversal(root);
    for (auto i : inorder)
    {
        cout << i << " ";
    }

    return 0;
}