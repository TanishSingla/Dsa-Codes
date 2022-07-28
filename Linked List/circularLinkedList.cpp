#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void insertAtHead(Node *&head, int d)
{
    // Creating node to be inserted at starting.
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}

void insertAtTail2(Node *&head, Node *&tail, int val)
{
    Node *n = new Node(val);
    if (head == NULL)
    {
        head = n;
        tail = n;
        head->next = head;
        return;
    }
    tail->next = n;
    n->next = head;
    tail = n;
    return;
}

void printCircular(Node *&head)
{
    if (head == NULL)
    {
        return;
    }
    Node *temp = head;
    do
    {
        cout << temp->data << "->";
        temp = temp->next;
    } while (temp != head);

    cout << endl;
    cout << "AFTER LOOP" << endl;
    cout << temp->data << "->";
    cout << temp->next->data;
    return;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int ele;
        cin >> ele;
        v.push_back(ele);
    }
    for (auto it : v)

    {
        insertAtTail2(head, tail, it);
    }

    printCircular(head);

    return 0;
}