#include<bits/stdc++.h>
using namespace std;

/*
class Node{
    public:
    int data;
    Node * next;
    Node(int d){
        this->data = d;
        this->next = NULL;
    }
};
Node * top = NULL;
void push(int d){
    Node * n = new Node(d);
    if(n){
        n->next = top;
        top=n;
    }else{
        cout << "Stack Overflow " <<'\n';
    }
}
int pop(){
    int x=-1;
    if(top){
        Node * n = top;
        x=n->data;
        top=top->next;
        // free(t);
    
    }else{cout << "Stack is Empty" <<'\n';}
    return x;
}

void display(){
    Node * temp = top;
    while(temp){
        cout << temp->data <<'\n';
        temp=temp->next;
    }
    cout  <<'\n';
}
*/

class Node{
public:
int data;
Node * next;
Node(int d){
    this->data=d;
    this->next = NULL;
}
};
class Stack{
    Node*top;
    public:
    Stack(){top==NULL;}
    void push(int x);
    int pop();
    void display();
};

void Stack::push(int x){
    Node * n = new Node(x);
    n->next = top;
    top=n;
}

int Stack::pop(){
    int x=-1;
    if(top==NULL)cout << "Empty Stack" <<'\n';
    else{
        x=top->data;
        Node * t = top;
        top=top->next;
        delete t;
    }
    return x;
}

void Stack::display()
{
    Node*p=top;
    while(p!=NULL){
        cout << p->data <<'\n';
        p=p->next;
    }
    cout  <<'\n';
}
int main(){

/*
//Stack Using Linked list
push(10);
push(30);
push(20);
display();
pop();
display();
*/

Stack s2;
s2.push(10);
s2.push(20);
s2.push(30);
s2.push(40);
s2.display();



    return 0;
}