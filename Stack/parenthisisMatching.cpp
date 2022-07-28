#include <bits/stdc++.h>
using namespace std;
class Stack
{
    int top;
    char *array;
    int size;

    Stack(int s)
    {
        this->size = s;
        arr = new int[size];
        top = -1;
    }

    void push(int ele)
    {
        if (size - top > 1)
        {
            top++;
            arr[top] = ele;
        }
        else
        {
            cout << "Stack Overflow" << '\n';
        }
    }
    void pop()
    {
        if (size == -1)
            cout << "Stack Underflow" << '\n';
        else
            top--;
    }
    int peek()
    {
        if (top >= 0 && top < size)
            return arr[top];
        else
            cout < < "Empty" < < '\n';
        return -1;
    }
    bool isEmpty()
    {
        return top == -1;
    }
};
bool isBalance(char *ch)
{
    Stack s;
    for (int i = 0; i != '\0'; i++)
    {
        if (ch[i] == ')')
            s.push(ch[i]);
        else if (s[i] == '(')
        {
            if (s.isEmpty())
                return false;
            s.pop();
        }
    }
    return s.isEmpty();
}
int main()
{

    //((a+b) * (c+d))
    char ch = "((a+b) * (c+d))";
    cout << isBalance(ch) << '\n';

    return 0;
}