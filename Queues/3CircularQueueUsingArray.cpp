
#include<iostream>
#include<queue>
using namespace std;
class CircularQueue
{
    int *arr;
    int size;
    int front;
    int rear;

    public:
    CircularQueue()
    {
        size = 10001;
        arr = new int[size];
        front = rear = -1;
    }

    bool isFull(int front, int rear, int size)
    {
        // there can be 2 scenarios wherein a circular queue can reach its full capacity. One wherein the front pointer
        // is at point 0 and the rear at the end of the array indicating that elements have been pushed throughout and
         // another wherein the array reached it max cap and then some popping operations took place followed by successive
        // pushing (wherein the rear moved from the start to the end and then back from the start).So in the second
        // scenario it is quite probable that the rear pointer is just behind the front one and there is no space
        // on either side of the array.
        if((front == 0 && rear == size - 1) || (rear == ((front - 1)%(size - 1))))
            return true;
        return false;
    }
    
    bool isEmpty(int front)
    {
        if(front == -1)
            return true;
        return false;
    }

    void enqueue(int value)
    {
        if(isFull(front,rear,size))
        {
            cout<<"Queue Overflow"<<endl;
            return;
        }
        // pushing first element
        else if(front == -1)
        {
            front = rear = 0;
        }
        // Now following the circular path (insertion from the front by moving the rear pointer to 0th index)
        else if(rear == size-1 && front != 0)
            rear = 0;
        // if all else if cases fail, then it means it is a case of normal insertion just like simple queue and
        // so we increment the rear pointer.
        else
            rear++;

        arr[rear] = value;
    }

    void dequeue()
    {
        if(isEmpty(front))
        {
            cout<<"Queue Underflow"<<endl;
        }
        // single element in queue
        else if(front == rear)
            front = rear = -1;
        // to maintain cyclic nature
        else if(front == size - 1)
            front = 0;
        // normal flow
        else
            front++;
    }
}

