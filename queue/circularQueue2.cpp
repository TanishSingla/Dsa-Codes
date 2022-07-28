class MyCircularQueue
{
public:
    int *arr;
    int rear = -1;
    int front = -1;
    int size = 0;
    MyCircularQueue(int k)
    {
        arr = new int[k];
        this->size = k;
    }

    bool enQueue(int value)
    {
        if (front == -1 && rear == -1)
        {
            // inserting first element :-
            front = rear = 0;
            arr[rear] = value;
            return true;
        }
        else if ((rear + 1) % size == front)
        {
            // full condition :-
            return false;
        }
        else
        {
            rear = (rear + 1) % size;
            arr[rear] = value;
            return true;
        }
        return true;
    }

    bool deQueue()
    {
        if (front == -1)
            return false;
        else if (front == rear)
        {
            front = rear = -1;
            return true;
        }
        else
        {
            front = (front + 1) % size;
            return true;
        }
        return true;
    }

    int Front()
    {
        if (front == -1)
            return -1;
        return arr[front];
    }

    int Rear()
    {
        if (rear == -1)
            return -1;
        return arr[rear];
    }

    bool isEmpty()
    {
        if (front == -1 && rear == -1)
            return true;
        return false;
    }

    bool isFull()
    {
        return (rear + 1) % size == front;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */