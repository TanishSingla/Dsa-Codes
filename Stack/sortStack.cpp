#include <bits/stdc++.h>
using namespace std;

void insertSorted(stack<int> &stack, int num)
{
    // base case
    if (stack.empty() || stack.top() < num)
    {
        stack.push(num);
        return;
    }

    int temp = stack.top();
    stack.pop();

    // recursive call
    insertSorted(stack, num);
    stack.push(temp);
}

void sortStack(stack<int> &stack)
{
    // Base case
    if (stack.empty())
        return;

    // sorting stack using recursion :-
    // we will pop every element from stack
    // then at returning time we will insert element in
    // sorted order.

    int n = stack.top();
    stack.pop();

    // recursive call
    sortStack(stack);

    // returning time we will insert in sorted order.
    insertSorted(stack, n);
}
int main()
{

    stack<int> s;
    s.push(3);
    s.push(4);
    s.push(9);
    s.push(0);
    s.push(-1);
    s.push(5);
    sortStack(s);

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}
// Time Complexity -> O(n^2)