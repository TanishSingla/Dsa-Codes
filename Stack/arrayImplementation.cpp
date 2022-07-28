#include<bits/stdc++.h>
using namespace std;

class Stack{
    public:
    int size;
    int *arr;
    int top;

    Stack(int s){
        size = s;
        top = -1;
        arr = new int[s];
    }

    //operations :- 
    void push(int ele){
        if(top==size-1){
            cout << "Stack Overflow" <<'\n';
            return;
        }else{
            top++;
            arr[top]=ele;
        }
    }

    void pop(){
        if(top==-1)cout << "Stack Underflow" <<'\n';
        else {
            top--;
        }
    }
    bool isEmpty(){
        if(top==-1)return true;
        else return false;
    }
    bool isFull(){
        if(top==size-1)return true;
        else return false;
    }

    void stackTop(){
        if(top==-1)cout <<"Stack is Empty "  <<'\n';
        else 
        cout << arr[top] <<'\n';
    }

    void peek(int pos){
        if(top==-1 )cout << "Stack is Empty" <<'\n';
        else 
        cout << arr[top-pos+1] <<'\n';
    }
};

void display(Stack s){

    for(int i=s.top; i>=0;i--){
        cout << s.arr[i]<<'\n';
    }
    cout  <<'\n';

}
int main(){
Stack s(5);
s.push(20);
s.push(30);
s.push(40);
s.push(50);
s.stackTop();
s.peek(3);
cout  <<'\n';
display(s);


    return 0;
}