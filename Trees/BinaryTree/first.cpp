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

Node *buildTreee(Node *root)
{
    cout << "Enter the data  " << '\n';
    int data;
    cin >> data;
    root = new Node(data);

    if (data == -1)
        return NULL;

    cout << "Enter data for left " << data << '\n';
    root->left = buildTreee(root->left);

    cout << "Enter data for right " << data << '\n';
    root->right = buildTreee(root->right);

    return root;
}

// level order traversal :-

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

// queue =[root,NULL]
// prints root.
// queue = [NULL,root->left,root->right].
// as q.front()==NULL. endl -> and q is not empty
//  so our queue will be = [root->left,root->right,NULL]
// prints root->left.
// prints root->right.

void reverseLevelOrderTraversal(Node *root)
{
    queue<Node *> q;
    stack<int> s;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            s.push(0);
            if (!q.empty())
                q.push(NULL);
        }

        else
        {
            s.push(temp->data);

            if (temp->right)
                q.push(temp->right);
            if (temp->left)
                q.push(temp->left);
        }
    }

    while (!s.empty())
    {
        if (s.top() == 0)
            cout << '\n';
        else
        {

            cout << s.top() << " ";
        }
        s.pop();
    }
}

// pre - order Traversal :-NLR
void preOrderTraversal(Node *root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

// inorder traversal :-  lNR
void inorderTraversal(Node *root)
{
    if (root == NULL)
        return;
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}
// post-order Traversal :-LRN
void postOrderTraversal(Node *root)
{
    if (root == NULL)
        return;
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}

void buildFromLevelTraversal(Node *&root)
{
    queue<Node *> q;
    int data;
    cout << "Enter Data For Root Node " << '\n';
    cin >> data;
    root = new Node(data);
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        cout << "Enter data for left of " << temp->data << '\n';
        int leftval;
        cin >> leftval;
        if (leftval != -1)
        {
            temp->left = new Node(leftval);
            q.push(temp->left);
        }
        cout << "Enter data for right of " << temp->data << '\n';
        int rightval
                cin >>
            rightval;
        if (right   val != -1)
        {
            temp->right = new Node(rightval);
            q.push(temp->right);
        }
    }
}
int main()
{
    Node *root = NULL;
    buildFromLevelTraversal(root);
    reverseLevelOrderTraversal(root);
    /*
    root = buildTreee(root);
    // 1 3 7 -1 -1 11 -1 -1  5 17 -1 -1 -1
    levelOrderTraversal(root);

    cout << '\n';

    cout << "Pre-Order" << '\n';
    preOrderTraversal(root);
    cout << '\n';

    cout << "Inorder" << '\n';
    inorderTraversal(root);
    cout << '\n';

    cout << "Post-Order" << '\n';
    postOrderTraversal(root);
    cout << '\n';
    */

    return 0;
}