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
        this->left = NULL;
        this->right = NULL;
    }
};

Node *buildTree(Node *root)
{
    int data;
    cout << "Enter Data " << endl;
    cin >> data;

    root = new Node(data);

    if (data == -1)
        return NULL;

    // for left
    cout << "Enter data for left of " << data << '\n';
    root->left = buildTree(root->left);

    // for right
    cout << "Enter data for right of " << data << '\n';
    root->right = buildTree(root->right);

    return root;
}

// level order Traversal :-
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

            cout << temp->data << "  ";

            if (temp->left != NULL)
                q.push(temp->left);
            if (temp->right != NULL)
                q.push(temp->right);
        }
    }
}
int main()
{
    Node *root = NULL;
    root = buildTree(root);
    levelOrderTraversal(root);

    return 0;
}