#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node *next;

    Node(int d){
        this->data = d;
        this->next = NULL;
    }
};
void insertAtHead(Node*&head,int d)
{
   Node * n = new Node(d);
   Node*temp = head;
   temp->next = head;
   while(temp->next!=head){
       temp=temp->next;
   }temp->next = n ;
}
void insertAtTail(Node*&head,Node*&tail,int val){

    Node * n = new Node(val);
    if(head==NULL){
        head=n;
        tail=n;
        head->next = head;
    return;
    }
    tail->next = n;
    n->next = head;
    tail = n;
    return;

}

void display(Node*head){
    Node * p = head;
    do{
        cout << p->data <<" ";
        p=p->next;
    }while(p!=head);
    cout  <<'\n';
}
void displayrecursively(Node *head,Node*p){


    static int flag = 0;
    if(head!=p || flag==0){
        flag=1;
        cout << p->data <<" ";
        displayrecursively(head,p->next);
    }
    flag = 0;
}
int main(){

Node *head = NULL;
Node *tail = NULL;
insertAtTail(head,tail,10);
insertAtTail(head,tail,20);
insertAtTail(head,tail,30);
insertAtTail(head,tail,40);
// insertAtTail(head,tail,50);
insertAtTail(head,tail,60);
display(head);
Node * p = head;
displayrecursively(head,p);
// cout << head->next->next->next->next->data <<'\n';
  return 0;
}