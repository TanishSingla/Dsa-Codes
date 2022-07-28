#include <iostream>
using namespace std;
class Queue
{
    int *arr;
    int front;
    int rear;
    int size;

public:
    Queue(int s)
    {
        this->size = s;
        front = rear = 0;
        arr = new int[s];
    }

    void push(int val)
    {
        if (rear == size)
            cout << "Queue is Full" << '\n';
        else
        {
            arr[rear] = val;
            rear++;
        }
    }

    void pop()
    {
        if (rear == front)
            cout << "Queue is Empty" << '\n';
        else
        {
            arr[front] = -1;
            front++;
        }
    }

    bool isEmpty()
    {
        return rear == front;
    }
    int qfront()
    {
        if (rear == front)
            return -1;
        else
            return arr[front];
    }
};
int main()
{
    Queue q(5);
    q.push(3);
    q.push(8);
    cout << "front-> " << q.qfront() << '\n';
    q.push(5);
    q.pop();
    cout << "front-> " << q.qfront() << '\n';
    q.push(4);

    return 0;
}