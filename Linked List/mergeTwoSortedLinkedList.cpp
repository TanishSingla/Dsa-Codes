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
    }else{
        n->next = head;
        head = n;
    }
}
void display(Node *head){
    while(head){
        cout << head->data <<" ";
        head = head->next;
    }

    cout  <<'\n';
}

void merge(Node*first,Node*second,Node *&third){
Node * last = NULL;
if(first->data < second->data){
    last = first;
    third = first;
    first = first->next;
    last->next = NULL;
}
else{
     last = second;
    third = second;
    second = second->next;
    last->next = NULL;
}
while(first!=NULL && second!=NULL){
    if(first->data < second->data){
        last->next = first;
        last = first;
        first = first->next;
        last->next= NULL;
    }
    else{
          last->next = second;
        last = second;
        second = second->next;
        last->next= NULL;
    }
}
if(first!=NULL){
    last->next = first;
}
else{
    last->next = second;
}

}
int main(){
//Linked List :- 
Node * first  = NULL;
insertAtHead(first,50);
insertAtHead(first,40);
insertAtHead(first,30);
insertAtHead(first,20);
insertAtHead(first,10);
display(first);

Node * second  = NULL;
insertAtHead(second,51);
insertAtHead(second,41);
insertAtHead(second,32);
insertAtHead(second,31);
insertAtHead(second,21);
display(second);

Node *third = NULL;
merge(first,second,third);
display(third);


    return 0;
}