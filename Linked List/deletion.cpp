#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

    // constructor :-
    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }

    // Destructor :-if the object is created by using new or the constructor uses new to allocate
    // memory which resides in the heap memory , the destructor should use delete to free the memory.
    ~Node()
    {
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "Memory free" << '\n';
    }
};

void deleteNode(Node *&head, int p)
{
    if (p == 1)
    {
        Node *temp = head;
        head = head->next;
        // memory free
        temp->next = NULL;
        delete temp;
    }
    else
    {
        // for deleting last or any middle node :-
        Node *curr = head;
        // curr -> current node which we have to delete.
        Node *prev = NULL;
        // prev -> previous node from the node we have to delte
        int cnt = 1;
        while (cnt < p)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }

        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}
void insertionAtHead(Node *&head, int d)
{
    Node *n = new Node(d);
    n->next = head;
    head = n;
}

void print(Node *&head)
{
    if (head == NULL)
    {
        cout << "List is empty " << endl;
        return;
    }
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << '\n';
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    Node *n = new Node(10);
    insertionAtHead(head, 50);
    insertionAtHead(head, 40);
    insertionAtHead(head, 30);
    insertionAtHead(head, 20);
    insertionAtHead(head, 10);
    deleteNode(head, 2);
    deleteNode(head, 1);
    deleteNode(head, 1);
    print(head);
    cout << '\n';
    cout << head->data << '\n';

    return 0;
}