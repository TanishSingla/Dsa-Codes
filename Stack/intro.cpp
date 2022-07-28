#include<iostream>
using namespace std;

class Stack{

public:
// we need 3 things for implementation of stack
//array , size and the top element for performing operations
int *arr;
int size;
int top;

Stack(int size){
    this->size = size;
    arr = new int[size];
    top=-1;
}

void push(int ele){
if(size - top> 1){
    top++;
    arr[top]=ele;
}
else{
    cout << "Stack Overflow " <<'\n';
}
}
void pop(){
    if(top>=0){
        top--;
    }else{
        cout << "Stack Underflow(stack is empty) " <<'\n';
    }

}
int peek(){
    if(top>=0 && top < size)
    return arr[top];
    else 
    cout << "Stack is Empty" <<'\n';
    return -1;

}
bool isEmpty(){
return top==-1;
}

};

// All operations -> O(1) -> Time Complexity.

int main(){


    //Stack Implementation :-
    // we can implement stack in two ways 
    // 1) Arrays
    // 2) Linked List
    
    Stack s1(5);
    s1.push(10);
    s1.push(20);
    s1.push(13);
    cout << s1.peek() <<'\n';
    s1.pop();
    cout << s1.peek() <<'\n';
    cout << s1.isEmpty() <<'\n';


    


    return 0; 
}
/*
    //STL -> Implementation
    //stack -> LIFO / FILO
    stack <int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << s.top() <<'\n';
    s.pop();
    cout << s.top() <<'\n';
    if(s.empty())cout << "Stack Is Empty" <<'\n';
    else cout << "Not Empty" <<'\n';
    cout <<" Size of Stack " << s.size()<<endl;


    //stack 2
    stack<int> s2;
    s2.push(90);
    s2.push(100);
    s2.push(1000);
    s2.push(10000);
    s2.swap(s);//used to swap elements of two stacks.
    cout << "stack 1 -> " << s.top() <<'\n';
    cout << "stack 2 -> " << s2.top() <<'\n';

*/