#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }
};

void sortLL(Node *head)
{

    int cnt0 = 0;
    int cnt1 = 0;
    int cnt2 = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == 0)
            cnt0++;
        else if (temp->data == 1)
            cnt1++;
        else
            cnt2++;

        temp = temp->next;
    }
    temp = head;

    while (temp)
    {
        if (cnt0)
        {
            temp->data = 0;
            cnt0--;
        }
        else if (cnt1)
        {
            temp->data = 1;
            cnt1--;
        }
        else if (cnt2)
        {
            temp->data = 2;
            cnt2--;
        }
        temp = temp->next;
    }
}

void insert(Node *&head, int d)
{
    Node *n = new Node(d);
    if (head == NULL)
        head = n;
    else
    {
        n->next = head;
        head = n;
    }
}
void display(Node *head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << '\n';
}

// without data replacement.

int main()
{

    Node *head = NULL;
    insert(head, 0);
    insert(head, 1);
    insert(head, 2);
    insert(head, 1);
    insert(head, 0);
    display(head);
    sortLL(head);
    display(head);

    // sorting linked list. (0,1,2 only)
    // 0 2 1 0 1 2
    // 0 0 1 1 2 2

    return 0;
}