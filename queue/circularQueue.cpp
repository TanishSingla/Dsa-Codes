#include <iostream>
using namespace std;

class CircularQueue
{
public:
    // Initialize your data structure.
    int rear;
    int front;
    int *arr;
    int size;
    CircularQueue(int n)
    {
        // Write your code here.
        this->size = n;
        arr = new int[n];
        front = rear = -1;
    }

    bool enque(int value)
    {
        // full condition :-
        if ((rear == size - 1 && front == 0) || (rear == (front - 1) % (size - 1)))
            return false;
        // for inserting first element :-
        else if (front == -1)
            rear = front = 0;
        else if (rear == size - 1 && front != 0)
            rear = 0;
        else
            rear++;
        arr[rear] = value;
        return true;
    }

    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue()
    {
        // empty condition :-
        if (front == -1)
            return -1;
        int x = arr[front];
        arr[front] = -1;
        if (front == size - 1)
            front = 0;
        else if (front == rear)
            front = rear = -1;
        else
            front++;
        return x;
    }
    void qfront() { cout << arr[front] << '\n'; }
};
int main()
{
    CircularQueue qc(4);
    qc.enque(3);
    qc.dequeue();
    qc.enque(1);
    qc.dequeue();
    qc.enque(2);
    qc.enque(4);
    qc.enque(6);
    qc.qfront();

    return 0;
}