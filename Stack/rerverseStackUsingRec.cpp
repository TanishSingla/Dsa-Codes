#include <bits/stdc++.h>
using namespace std;
class Stack
{
public:
    int size;
    int *arr;
    int top;

    Stack(int s)
    {
        this->size = s;
        top = -1;
        arr = new int[size];
    }

    void push(int ele)
    {
        if (top == size - 1)
        {
            cout << "Stack Overflow" << '\n';
        }
        else
        {
            top++;
            arr[top] = ele;
        }
    }
    void pop()
    {
        if (top == -1)
            cout << "Stack is empty" << '\n';
        else
        {
            top--;
        }
    }
    bool empty()
    {
        if (top == -1)
            return true;
        else
            return false;
    }
};
void display(Stack s)
{
    for (int i = s.top; i >= 0; i--)
    {
        cout << s.arr[i] << '\n';
    }
    cout << '\n';
}

void insertAtBottom(Stack &s, int temp)
{
    if (s.empty())
    {
        s.push(temp);
        return;
    }

    int t = s.top;
    s.pop();
    insertAtBottom(s, temp);
    s.push(t);
}

void reverseStack(Stack &s)
{
    if (s.empty())
        return;
    int temp = s.top;
    s.pop();

    // recursive call
    reverseStack(s);

    // insert
    insertAtBottom(s, temp);
}

int main()
{
    Stack s(6);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    display(s);
    reverseStack(s);
    display(s);

    return 0;
}