#include<iostream>
#include<queue>
using namespace std;
class Queue
{
    // initially front & rear will point to 0th index because no element has been inserted or deleted till now

    int *arr;
    int front; 
    int rear;
    int size;
    
    Queue()
    {
        size = 10001;
        front = rear = 0;
        arr = new int[size];
    }

    bool isFull(int rear, int size)
    {
        if(rear == size)
            return true;
        return false;
    }

    bool isEmpty(int front, int rear)
    {
        if(front == rear)
            return true;
        return false;
    }

    // insert in queue
    void enqueue(int data)
    {
        if(isFull(rear, size))
            cout<<" Queue Overflow "<<endl;
        else
        {
            arr[rear] = data;
            rear++;
        }
        return ;
    }

    // delete in queue
    void dequeue()
    {
        if(isEmpty(front, rear))
            cout<<" Queue Underflow "<<endl;
        else
        {
            arr[front] = -1;
            front++;
            // Let's say you ended up popping elements from queue, it is now important to reset the front
            // and rear pointer to their default values to carry out later push operations.
            if(front == rear)
            {
                front = 0;
                rear = 0;
            }
        }
    }

};