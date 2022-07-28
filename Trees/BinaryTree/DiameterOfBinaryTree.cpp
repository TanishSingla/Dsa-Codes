#include <bits/stdc++.h>
using namespace std;
class Node
{
    int data;
    Node left;
    Node right;

    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *buildTree(Node *root)
{
    cout << "Enter The Data " << endl;
    int val;
    cin >> val;
    root = new Node(val);

    if (val == -1)
        return NULL;

    cout << "Enter data for left node" << '\n';
    root->left = buildTree(root->left);

    cout << "Enter data for right node" << '\n';
    root->right = buildTree(root->right);

    return root;
}

void levelOrderTraversal(Node *root)
{
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
            if (!q.empty())
                q.push(NULL);
        }
        else
        {
            cout << temp->data << " ";
            if (temp->data != NULL)
                q.push(temp->left);
            if (temp->right != NULL)
                q.push(temp->right);
        }
    }
}

// O(n^2) :-
int diameter(Node *root)
{
    if (root == NULL)
        return 0;

    // option 1 :-
    int left = diameter(root->left);

    // op 2 :-
    int right = diameter(root->right);

    // op 3 :-
    int both = ht(root->left) + 1 + ht(root->right);

    int ans = max(left, max(right, both));

    return ans;
}
int main()
{
    // diameter of binary tree :- largest path b/w two ending nodes.

    return 0;
}