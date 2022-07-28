#include <bits/stdc++.h>
using namespace std;
queue<int> firstApproach(queue<int> &q)
{
    // using stack
    stack<int> s;
    while (!q.empty())
    {
        s.push(q.front());
        q.pop();
    }
    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
    }
    return q;
}

void sol(queue<int> &q)
{
    if (q.size() != 0)
    {
        int x = q.front();
        q.pop();
        sol(q);
        q.push(x);
    }
}
queue<int> usingRecursion(queue<int> &q)
{
    sol(q);
    return q;
}
int main()
{

    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    firstApproach(q);
    // cout << q.front() << '\n';
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << '\n';
    queue<int> q2;
    q2.push(1);
    q2.push(2);
    q2.push(3);
    q2.push(4);
    usingRecursion(q2);
    while (!q2.empty())
    {
        cout << q2.front() << " ";
        q2.pop();
    }

    return 0;
}