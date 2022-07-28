#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node * next;

  
    Node(int d){
        this->data = d;
        this->next = NULL;
    }
};

void display(Node *head){
    while(head){
        cout << head->data <<" ";
        head = head->next;
    }cout  <<'\n';
}

void insertAtHead(Node *&head,int d){
    Node *n = new Node(d);
    n->next = head;
    head=n;
}
void insert(Node *&head,int p,int d){
    if(p==0)insertAtHead(head,d);
    else{
        Node * n = new Node(d);
        Node * temp = head;
        while(p-1){
            temp = temp->next;
            p--;
        }
        n->next = temp->next;
        temp->next = n;
        return;

    }
}
int RCount(Node *head){
    int cnt=0;
    while(head){
        head=head->next;
        cnt++;
    }
    return cnt;
}

int RSum(Node *head){
    int sum = 0;
    while(head){
        sum = sum + head->data;
        head = head->next;
    }
    return sum;
}
void reverseLL(Node*&head){
    Node * curr = head;
    Node * prev = NULL;
    Node * pp = NULL;
    while(curr !=NULL){
        pp = prev;
        prev = curr;
        curr=curr->next;
        prev->next = pp;
    }
    head = prev;
}
void rrhelper(Node*&head,Node*prev,Node*curr){
    if(curr!=NULL){
        rrhelper(head,curr,curr->next);
        curr->next = prev;
    }
    else{
        head = prev;
    }
}
void reverseRecursively(Node *&head){
    Node * prev = NULL;
    Node * curr = head;
    rrhelper(head,prev,curr);
}
int max(Node *head){
    int x=-1;
    if(head==NULL)return x;
    x = max(head->next);
    return x>head->data ? x: head->data;
}

Node * search(Node *head,int key){

    if(head==NULL)return NULL;
    if(key==head->data){
        return head;
    }
    return search(head->next,key);  
}

void insertionSortedList(Node *&head,int d){
    Node *n = new Node(d);
    Node *prev = NULL;
    Node *curr = head;
    while(curr && curr->data < d){
        prev = curr;
        curr = curr->next;
    }
    n->next = prev->next;
    prev->next = n;
}

bool sorted(Node *head){
    Node * temp = head->next;
    while(temp!=NULL){
        if(head->data > temp->data)return false;
        head = head->next;
        temp=temp->next;
    }
    return true;
}
bool checkLoop(Node*head){
     
 Node *p = head;
 Node *q = head;
 do{
     p = p->next;
     q = q->next;
     q = q!=NULL?q->next:NULL;
 }while(p&&q   && p!=q);
 return p==q?true:false;
}

//circular Linekd List :- 
void displaycllR(Node*head){
    static int flag = 0;
    static Node * temp = head;
    if(flag==0 || head!=temp){
        flag=1; 
        cout << temp->data <<'\n';
        displaycllR(temp->next);
    }
    flag=0;     
}
int main(){

/*
Node * head = NULL;
insertAtHead(head,50);
insertAtHead(head,40);
insertAtHead(head,30);
insertAtHead(head,20);
insert(head,2,35);
insertionSortedList(head,41);

// int count  = RCount(head);
// cout << "Number of Nodes "<< count <<'\n';
// int sum = RSum(head);
// cout << "Sum of Nodes "<<RSum(head) <<'\n';
// cout << "Maximum element is "<<max(head) <<'\n';
// Node * temp = search(head,100);
// cout <<"Data Found "<< temp->data <<'\n';
display(head);
cout  <<'\n';
if(sorted(head))cout << "Sorted" <<'\n';
else cout << "Not Sorted" <<'\n';

*/

/*
Node * first = NULL;
insertAtHead(first,10);
insertAtHead(first,20);
insertAtHead(first,30);
insertAtHead(first,40);
insertAtHead(first,50);
insertAtHead(first,60);
insertAtHead(first,70);
insertAtHead(first,80);
display(first);
reverseRecursively(first);
display(first);
bool c = checkLoop(first);
cout << c <<'\n';
*/
Node * circular = NULL;
insertAtHead(circular,10);
insertAtHead(circular,20);
insertAtHead(circular,30);
insertAtHead(circular,40);
circular->next->next->next->next = circular;
displaycllR(circular);
    return 0;
}