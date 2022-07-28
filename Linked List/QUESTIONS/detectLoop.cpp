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

void insert(Node *&head,int v){
    Node * n = new Node(v);
    if(head==NULL)head = n;
    else{
    n->next = head;
    head = n;
    }
}
void display(Node *head){
    while(head!=NULL){
        cout << head->data <<" ";
        head=head->next;
    }
}

bool loop(Node*head){
    //floyd's cycle detection
    //space o(1)
    if(head==NULL)return false;
    Node * sl = head;
    Node *fast  = head;
    while(sl && fast ){
        sl = sl->next;
        fast = fast->next;
        fast = fast=!NULL?fast->next:NULL;
        if(sl==fast)return true;
    }
     return false;
}

bool detectLoopMap(Node *head){

    //space Complexity -> o(n)
    //Time Complexity -> o(n)
    if(head ==NULL)return false;

    map<Node *,bool> visited;
    Node * temp = head;
    while(temp){
        if(visited[temp]==true){
            cout << temp->data <<'\n';
            return 1;
            }

        visited[temp]= true;
        temp = temp->next;
    }
    return 0;
}
int main(){

Node *h1 = NULL;
insert(h1,40);
insert(h1,30); 
insert(h1,20);
insert(h1,10);
 h1->next->next->next->next = h1->next;
cout <<loop(h1) <<'\n';


    return 0;
}