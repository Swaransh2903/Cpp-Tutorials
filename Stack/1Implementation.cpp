// LIFO - Last In First Out

// Operations : Push, Peek(top element dekhne keliye), Pop, Empty

// STL : stack<int> s; s.push(5), s.top() , s.empty(), s.pop()


// Array Implementation:

#include<iostream>
using namespace std;
class Stack{

    // properties
    public:
        int *arr;
        int top;
        int size;

    // behaviour
    Stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    } 

    bool isFull()
    {
        if((size-top) <= 1)
            return true;
        return false;
    }

    bool isEmpty()
    {
        if(top < 0)
            return true;
        return false;
    }

    void push(int element)
    {
        if(isFull())
            cout<< "Stack overflow" << endl;
        else
        {
            top++;
            arr[top] = element;
        }
    }
    void pop()
    {
        if(isEmpty())
            cout<< "Stack Underflow" <<endl;
        else
        {
            top--;
        }
    }
    int peek()
    {
        if(isEmpty())
        {
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        else
        {
            return arr[top];
        }
    }
};
int main()
{
    Stack st(5);
    st.push(23);
    st.push(45);
    st.push(45);
    st.push(45);
    st.push(43);
    st.push(43);

    // int topmost = st.peek();
    // if(topmost!=-1)
    //     cout << "The top element is: " <<topmost<<endl;

}
