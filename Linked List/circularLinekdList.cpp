/*
#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *next;

    //constructor
    Node(int data){
        this->data = data;
        this->next = NULL;
    }

    ~Node(){
        int v = this->data;
        if(this->next = NULL){
            delete next;
            next = NULL;
        }
        cout << "Memory free for Node "<<v <<'\n';
    }
};

void insertNode(Node *&tail,int ele,int d){

    //assuming our list is having element(ele)

    //if our list is empty
    if(tail ==NULL){
    Node* n = new Node(d);
    tail = n;
    n->next = n;
    }
    else{
        //list is not empty :- 

        Node * curr = tail;
        while(curr->data != ele){
            curr = curr->next;
        }
        //element found -> curr is representing ele  node.
        Node*temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}

void print(Node *tail){
    Node *temp = tail;

    do {
        cout << tail->data <<" ";
        tail = tail->next;
    }
    while(tail!=temp);
    cout  <<'\n';
    /*
    //this will not print if we have only 1 node
    Node* temp = tail;
    while((tail->next!=temp)){
        cout << temp->data <<" ";
        temp=temp->next;
    }
    cout  <<'\n';
    
}
void deletion(Node *&tail,int v){
//empty list 
if(tail==NULL)return;
else{
     // assuming value(Node which we have to delete) is present in linked list
     Node*prev = NULL;
     Node*curr = prev->next;
     while(curr->data!=v){
         prev = curr;
         curr = curr->next;
     }
     prev ->next = curr->next;
     curr->next = NULL;
    delete curr;
}
}
// https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms?source=youtube&campaign=YouTube_CodestudioLovebabbar23rdJan&utm_source=youtube&utm_medium=affiliate&utm_campaign=YouTube_CodestudioLovebabbar23rdJan
int main()
{

    // circular linked list :- Circular linked list is a linked list where
    // all nodes are connected to form a circle.
    // There is no NULL at the end. A circular linked
    // list can be a singly circular linked list or doubly circular linked list.
    // Any node can be a starting point. We can traverse the whole list by starting
    // from any point. We just need to stop when the first visited node is visited again.

    Node *tail  = NULL;
    insertNode(tail,5,3);
    print(tail);
    insertNode(tail,3,100);
    print(tail);
    insertNode(tail,5,1000);
    // print(tail);
    print(tail);
    

    return 0;
}
 */
#include<iostream>
#include<map>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    //constrcutor
    Node(int d) {
        this->data = d;
        this->next = NULL;
    }

    ~Node() {
        int value = this->data;
        if(this->next != NULL) {
            delete next;
            next = NULL;
        }
        cout << " memory is free for node with data " << value << endl;
    }

};

void insertNode(Node* &tail, int element, int d) {
    

    //empty list
    if(tail == NULL) {
        Node* newNode = new Node(d);
        tail = newNode;
        newNode -> next = newNode;
    }
    else{
        //non-empty list
        //assuming that the element is present in the list

        Node* curr = tail;

        while(curr->data != element) {
            curr = curr -> next;
        }
        
        //element found -> curr is representing element wala node
        Node* temp = new Node(d);
        temp -> next = curr -> next;
        curr -> next = temp;

    }

}    

void print(Node* tail) {

    Node* temp = tail;

    //empty list
    if(tail == NULL) {
        cout << "List is Empty "<< endl;
        return ;
    }

    do {
        cout << tail -> data << " ";
        tail = tail -> next;
    } while(tail != temp);

    cout << endl;
} 

void deleteNode(Node* &tail, int value) {

    //empty list
    if(tail == NULL) {
        cout << " List is empty, please check again" << endl;
        return;
    }
    else{
        //non-empty

        //assuming that "value" is present in the Linked List
        Node* prev = tail;
        Node* curr = prev -> next;

        while(curr -> data != value) {
            prev = curr;
            curr = curr -> next;
        }

        prev -> next = curr -> next;

        //1 Node Linked List
        if(curr == prev) {
            tail = NULL;
        }

        //>=2 Node linked list
        else if(tail == curr ) {
            tail = prev;
        }

        curr -> next = NULL;
        delete curr;

    }

}

bool isCircularList(Node* head) {
    //empty list
    if(head == NULL) {
        return true;
    }

    Node* temp = head -> next;
    while(temp != NULL && temp != head ) {
        temp = temp -> next;
    }

    if(temp == head ) {
        return true;
    }

    return false;

}

bool detectLoop(Node* head) {

    if(head == NULL)
        return false;

    map<Node*, bool> visited;

    Node* temp = head;

    while(temp !=NULL) {

        //cycle is present
        if(visited[temp] == true) {
            return true;
        }

        visited[temp] = true;
        temp = temp -> next;

    }
    return false;

}


int main() {

    Node* tail = NULL;

   // insertNode(tail, 5, 3);
    //print(tail);

  //  insertNode(tail, 3, 5);
   // print(tail);

/*
    insertNode(tail, 5, 7);
    print(tail);

    insertNode(tail, 7, 9);
    print(tail);

    insertNode(tail, 5, 6);
    print(tail);
    
    insertNode(tail, 9, 10);
    print(tail);

    insertNode(tail, 3, 4);
    print(tail);
   

    deleteNode(tail, 5);
    print(tail);
     */

    if(isCircularList(tail)) {
        cout << " Linked List is Circular in nature" << endl;
    }
    else{
        cout << "Linked List is not Circular " << endl;
    }

    return 0;
}