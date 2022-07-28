#include <iostream>
using namespace std;
class stack
{
public:
    int *arr;
    int size;
    int top1, top2;

    stack(int s)
    {
        this->size = s;
        arr = new int[s];
        top1 = -1;
        top2 = s;
    }

    void push1(int ele)
    {
        if (top1 < top2 - 1)
        {
            top1++;
            arr[top1] = ele;
        }
        else
        {
            cout << "Stack1 Overflow" << '\n';
        }
    }
    void push2(int ele)
    {
        if (top2 - 1 > top1)
        {
            top2--;
            arr[top2] = ele;
        }
        else
        {
            cout << "Stack Overflow" << '\n';
        }
    }
    void pop1()
    {
        if (top1 != -1)
            top1--;
        else
            cout << "Stack Underflow" << '\n';
    }
    void pop2()
    {
        if (top2 < size)
            top2++;
        else
            cout << "Stack Underflow" << '\n';
    }
    int peek1()
    {
        if (top1 != -1)
            return arr[top1];
        return -1;
    }
    int peek2()
    {
        if (top2 < size)
            return arr[top2];
        return -1;
    }
};
int main()
{
    stack s(6);
    s.push1(1);
    s.push1(2);
    s.push2(3);
    s.push2(3);
    s.push2(3);
    cout << s.peek1() << '\n';
    cout << s.peek2() << '\n';

    return 0;
}