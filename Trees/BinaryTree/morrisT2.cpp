#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *buildTree(Node *&root)
{

    cout << "Enter Data for Node" << '\n';
    int data;
    cin >> data;
    root = new Node(data);
    if (data == -1)
        return NULL;

    cout << "Enter data for left of" << data << '\n';
    root->left = buildTree(root->left);

    cout << "Enter data for right of " << data << '\n';
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

// Morris Traversal.
vector<int> morrisTraversalInorder(Node *root)
{

    Node *curr = root;
    vector<int> ans;

    while (curr != NULL)
    {
        if (curr->left == NULL)
        {
            ans.push_back(curr->data);
            curr = curr->right;
        }
        else
        {
            Node *prev = curr->left;

            // moving to its rightmost node.
            while (prev->right && prev->right != curr)
            {
                prev = prev->right;
            }
            if (prev->right == NULL)
            {
                // making thread
                prev->right = curr;
                curr = curr->left;
            }
            else
            {
                prev->right = NULL;
                ans.push_back(curr->data);
                curr = curr->right;
            }
        }
    }
    return ans;
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
    vector<int> inorder = morrisTraversalInorder(root);
    for (auto i : inorder)
    {
        cout << i << " ";
    }

    return 0;
}