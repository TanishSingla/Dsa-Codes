#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;   // to store data
    Node *next; // pointer for pointing to next node (for storing next node adress)

    // constructor :-
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

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

void insertAtHead(Node *&head, int d)
{
    // Creating node to be inserted at starting.
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}
void insertAtTail(Node *&tail, int d)
{
    // adding element in  klast
    Node *temp = new Node(d);
    tail->next = temp;
    tail = temp;
}

void insertionAtPosition(Node *&tail, Node *&head, int position, int data)
{
    if (head == NULL)
    {
        return;
    }
    // inserting at starting
    if (position == 1)
    {
        insertAtHead(head, data);
        return;
    }
    // inserting at last :- as if we add element in last
    // then we have to update our tail element also.
    Node *temp = head;
    if (temp->next == NULL)
    {
        insertAtTail(tail, data);
        return;
    }

    // creating node which has to be inserted.
    Node *nodeToInsert = new Node(data);

    // if we have to insert at n poisiton then we will traverse till (n-1).
    int cnt = 1;

    // creating a tempraray node for traversing till (position - 1).
    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }

    // we have to insert node between temp
    // and its next node
    //  so thats why we used this ....
    nodeToInsert->next = temp->next;

    // now to add link of new node we used this..
    temp->next = nodeToInsert;
}
void insertAtTail2(Node *&head, Node *&tail, int val)
{
    Node *n = new Node(val);
    if (head == NULL)
    {
        head = n;
        tail = n;
        return;
    }
    tail->next = n;
    tail = n;
    return;
}

int main()
{

    // Linked List :- It is a linear dataStructure,in which elements are not stored in
    // contiguous memory locations.
    // a linked list is consist of nodes where each node is having a data
    // and the adress to the next node.
    // we have 5 types of linked list :-
    // Singly linked list
    // Doubly linked list
    // Circular linked list
    // Circular doubly linekd list.

    //
    /*
    Node *node1 = new Node(10);
    cout << node1->data << endl;
    cout << node1->next << endl;
    Node *head = node1;
    Node *tail = node1;
    // as there is one element so it will be head as well as tail.
    print(head);
    // insertAtHead(head, 12);
    // insertAtHead(head, 11);
    insertAtTail(tail, 22);
    insertAtTail(tail, 92);
    print(head);

    // insert in middle
    insertionAtPosition(head, 3, 100);
    print(head);
    */

    // Node *head = NULL;
    // Node *tail = NULL;
    // insertAtTail2(head, tail, 46737);
    // insertAtTail2(head, tail, 364);
    // insertAtTail2(head, tail, 3484);
    // insertAtTail2(head, tail, 4);
    // insertAtTail2(head, tail, 5);
    // insertAtTail2(head, tail, 6);
    // insertAtTail2(head, tail, 6);
    // insertAtTail2(head, tail, 6);
    // insertAtTail2(head, tail, 6);
    // insertAtTail2(head, tail, 6);

    /*
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
            insertAtHead(head, it);
        }
        print(head);
        insertionAtPosition(tail, head, 2, 100);
        print(head);
    */
    // singly linked list :-
    // A singly linked list is a type of linked list that is unidirectional,
    // that is, it can be traversed in only one direction from head to the last node (tail).
    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;
    print(head);
    insertAtTail(tail, 17);
    insertAtTail(tail, 22);
    print(head);
    cout << '\n';
    insertionAtPosition(tail, head, 2, 100);
    print(head);
    cout << head->data << '\n';
    cout << tail->data << '\n';

    return 0;
}