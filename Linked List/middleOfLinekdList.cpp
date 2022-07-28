#include<bits/stdc++.h>
using namespace std;
class Node{
    public:

int data;
Node*next;
Node(int d){
    this->data = d;
    this->next = NULL;
}
};
//we can find the middle Node by finding length also
//time complexity of that function and this one will be same
//but we have done this in one traversal.
void insert(Node*&head,int d){

    Node *n = new Node(d);
    if(head==NULL){
        head=n;
    }
    else{
        n->next = head;
        head=n;
    }
}
void display(Node *head){
    while(head){
        cout << head->data <<" ";
        head=head->next;
    }
    cout  <<'\n';
}
Node *findMiddle(Node*head){
    Node * sl = head;
    Node * fast = head;
    while(fast!=NULL && fast->next!=NULL){
        sl = sl->next;
        fast = fast->next->next;
    }
    return sl;
}
Node *findMiddle2(Node*head){
    Node*sl = head;
    Node*fast = head;
    while(fast){
            fast = fast->next;
            if(fast)fast = fast->next;
            if(fast)sl = sl->next;
    }
    return sl;
}
int main(){
Node * head = NULL;
insert(head,70);
insert(head,60);
insert(head,50);
insert(head,40);
insert(head,30);
insert(head,20);
insert(head,10);
display(head);
Node * middle  = findMiddle(head);
Node * middle2  = findMiddle2(head);
cout << middle->data <<'\n';
cout << middle2->data <<'\n';



    return 0;
}