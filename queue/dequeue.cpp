// Deque or Double Ended Queue is a generalized version
// of Queue data structure that allows insert and delete at both ends.

/*
-> Operations on Dequeue :-
insertFront(): Adds an item at the front of Deque.
insertLast(): Adds an item at the rear of Deque.
deleteFront(): Deletes an item from the front of Deque.
deleteLast(): Deletes an item from the rear of Deque. In addition to the above operations, the following operations are also supported.
getFront(): Gets the front item from the queue.
getRear(): Gets the last item from queue.
isEmpty(): Checks whether Deque is empty or not.
isFull(): Checks whether Deque is full or not.


Applications of Deque: Since Deque supports both stack and queue operations,
it can be used as both. The Deque data structure supports clockwise and anticlockwise
rotations in O(1) time which can be useful in certain applications. Also, the problems
where elements need to be removed and or added to both ends can be efficiently solved using Deque
*/

#include <iostream>
using namespace std;
#include <queue>
int main()
{
    /*
    // STL implementation :-
    deque<int> d;
    d.push_front(14);
    d.push_back(10);
    cout << d.front() << '\n';
    cout << d.back() << '\n';
    d.pop_front();
    cout << d.front() << '\n';
    cout << d.back() << '\n';
    d.pop_back();
    cout << d.front() << '\n';
    cout << d.empty() << '\n';
    */
    return 0;
}