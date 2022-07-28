#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node * next;

    Node(int d){
        this->data = d;
        this->next = NULL;
    }
};

void insertAtHead(Node *&head,int d){
    Node *n = new Node(d);
    if(head==NULL){
    head = n;
    return;
    }
    else{
        n->next = head;
        head = n;
    }
}
void display(Node*head){
    while(head){
        cout << head->data <<" ";
        head=head->next;
    }
    cout  <<'\n';
}
void helper(Node*&head,Node*&curr,Node*&prev){
    if(curr){
        helper(head,curr->next,curr);
        curr->next = prev;
    }else{
        head=prev;
    }
}
void reversse(Node*&head){
    Node * curr = head;
    Node * prev = NULL;
    helper(head,curr,prev);
}
int main(){

    Node * head = NULL;
    insertAtHead(head,1);
    insertAtHead(head,2);
    insertAtHead(head,3);
    insertAtHead(head,4);
    insertAtHead(head,5);
    insertAtHead(head,6);
    display(head);
    reversse(head);
    
    display(head);
    return 0;
}