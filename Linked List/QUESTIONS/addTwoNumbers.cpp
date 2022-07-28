//https://leetcode.com/problems/add-two-numbers/
#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node*next;

    Node(int d){
        this->data = d;
        this->next=NULL;
    }
};

Node *addTwoNumbers(Node *l1,Node *l2){

    Node * dummy = new Node();
    Node *temp = dummy;
    int carry = 0;

    while(l1!=NULL || l2!=NULL || carry){
        int sum = 0;
        if(l1!=NULL){
            sum += l1->data;
            l1=l1->next;
        }
        if(l2!=NULL){
            sum+= l2->data;
            l2=l2->next;
        }
        sum +=carry;
        carry = sum/10;
        Node *n = new Node(sum%10);
        temp->next = n;
        temp = temp->next;
    }
    return dummy->next;
}

void print(Node*head){
    while(head!=NULL){
        cout << head->data <<" ";
        head= head->next;
    }
    cout  <<'\n';
}
void insertAtTail(Node *&tail,int v){
    Node * n = new Node(v);
    tail->next = n;
    tail = n;
}
int main(){

// L1 -> 2->4->3
// L2 -> 5->6->4
// Output -> 7->0->8

Node *n1 = new Node(10);
Node *tail = n1;
Node *head = n1;
insertAtTail(tail,20);
insertAtTail(tail,20);
print(head);

    return 0;
}