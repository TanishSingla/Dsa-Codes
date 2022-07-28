#include <iostream>
using namespace std;
#include <queue>

int main()
{
    // STL -> Implementation
    queue<int> q;
    q.push(28);
    q.push(4);
    cout << "Front -> " << q.front() << '\n';
    q.push(1);
    cout << "Front -> " << q.front() << '\n';
    q.push(2);
    q.push(8);
    cout << "size->" << q.size() << '\n';
    q.pop();
    cout << "size->" << q.size() << '\n';

    cout << "Empty -> " << q.empty() << '\n';
    q.emplace(10);
    // emplace -> add element in last (like push)
    cout << "Size " << q.size() << '\n';

    return 0;
}