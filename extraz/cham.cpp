#include <bits/stdc++.h>
using namespace std;
// stack :-
class Stack
{
    int top;
    int size;
    int *arr;
    Stack(int s)
    {
        this->size = s;
        arr = new int[size];
        top = -1;
    }
    void push(int ele)
    {
        if (top == size - 1)
        {
            cout << "Stack OVERFLOW" << '\n';
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
        {
            cout << "Stack is Empty" << '\n';
        }
    }
    else
    {
        top--;
    }

    int peek(int pos)
    {
        // top - pos + 1 = index of the array.
        int x = -1;
        if (top - pos + 1 < 0)
            cout << "Invalid Position" << '\n';
        else
        {
            x = arr[top - pos + 1];
        }
        return x;
    }
    bool isEmpty()
    {
        if (top == -1)
            return false;
        return true;
    }

    bool isFull()
    {
        if (top == size - 1)
            return true;
        else
            return false;
    }
};
int main()
{

    return 0;
}