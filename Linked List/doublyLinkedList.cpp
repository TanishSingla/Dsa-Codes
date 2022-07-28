#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    // Doubly linked List :-
    int data;
    Node *next;
    Node *prev;

    // constructor :-
    Node(int d)
    {
        this->data = d;
        this->next = NULL;
        this->prev = NULL;
    }

    ~Node()
    {
        int val = this->data;
        if (next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "Memory free for node having data " << val << '\n';
    }
};

void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << '\n';
}

int getLength(Node *&head)
{
    int length = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        length++;
        temp = temp->next;
    }
    return length;
}
void insertAtHead(Node *&head, Node *&tail, int value)
{
    if (head == NULL)
    {
        Node *n = new Node(value);
        head = n;
        tail = n;
    }
    else
    {
        Node *n = new Node(value);
        n->next = head;
        head->prev = n;
        head = n;
    }
}

void insertAtTail(Node *&head, Node *&tail, int d)
{
    if (head == NULL)
    {
        Node *n = new Node(d);
        head = n;
        tail = n;
    }
    else
    {
        Node *n = new Node(d);
        tail->next = n;
        n->prev = tail;
        tail = n;
    }
}
void insertAtPosition(Node *&tail, Node *&head, int d, int p)
{
    Node *n = new Node(d);

    // insertion at head.
    if (p == 1)
    {
        insertAtHead(head, tail, d);
    }
    // insertion at positon.
    // traversing till (n-1) node.
    Node *temp = head;
    int cnt = 1;
    while (cnt < p - 1)
    {
        temp = temp->next;
        cnt++;
    }
    if (temp->next == NULL)
    {
        insertAtTail(head, tail, d);
        return;
    }
    // insert at middle
    /*
    temp->next->prev = n;
    Node *store = temp->next;
    temp->next = n;
    n->prev = temp;
    n->next = store;
    */
    n->next = temp->next;
    temp->next->prev = n;
    temp->next = n;
    n->prev = temp;
    return;
}

// deletion :-

void deleteNode(Node *&head, int p)
{
    // deleting first i.e head node :-
    if (p == 1)
    {
        Node *temp = head;
        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }

    // deleting from middle or last position....
    int cnt = 1;
    Node *curr = head;
    Node *pre = NULL;
    while (cnt < p)
    {
        pre = curr;
        curr = curr->next;
        cnt++;
    }
    // 1 2 3 4 5
    curr->prev = NULL;
    pre->next = curr->next;
    curr->next->prev = pre;
    curr->next = NULL;
    delete curr;
}

int main()
{
    // A Doubly Linked List (DLL) :-  contains an extra pointer,
    // typically called previous pointer, together with next
    // pointer and data which are there in singly linked list.

    // Advantages over singly linked list
    // 1) A DLL can be traversed in both forward and backward direction.
    // 2) The delete operation in DLL is more efficient if pointer to the node to be deleted is given.
    // 3) We can quickly insert a new node before a given node

    // Node *n = new Node(10);
    // Node *head = n;
    // Node *tail = n;
    Node *head = NULL;
    Node *tail = NULL;
    // insertAtHead(head, 30);
    // insertAtHead(head, 40);
    insertAtTail(head, tail, 100);
    insertAtTail(head, tail, 300);
    insertAtTail(head, tail, 400);
    insertAtTail(head, tail, 500);
    print(head);
    int l = getLength(head);
    // cout << "Length is " << l << '\n';
    insertAtPosition(tail, head, 200, 3);
    insertAtPosition(tail, head, 2000, 1);
    insertAtPosition(tail, head, 20000, 8);
    print(head);

    deleteNode(head, 3);
    deleteNode(head, 1);
    deleteNode(head, 4);
    print(head);
    return 0;
}