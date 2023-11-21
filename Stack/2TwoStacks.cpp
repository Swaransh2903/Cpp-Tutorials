#include<iostream>
using namespace std;
class TwoStack
{

    int size;
    int top1;
    int top2;
    int* arr;

    public:

        // constructor initializations:
        TwoStack(int s)
        {
            this->size = s;
            // in first stack we'll be pushing elements from left to right and so we have taken a top pointer that
            // initially stores -1.
            int top1 = -1;
            // in second stack, we'll be inserting elements from right to left & so we have take another top pointer
            // that initially stores size of array.
            int top2 = s;
            arr = new int[s];
        }

        // stack 1 push function:
        void push1(int num)
        {
            // when can we push ? -> when there is an empty space available -> for first stack , we are incrementing
            // from left to right & for the second stack vice versa, so if the difference b/w the two pointers
            // (top1 & top2) is greater than 1, that means there is availability of space
            if((top2-top1) > 1)
            {
                // since this is the push function for stack 1 the top pointer for it will be incremented & then
                // we'll insert an element because movement is from left to right.
                top1++;
                arr[top1] = num;
            }
            else
                cout<< "Stack Overflow" <<endl;
        }

        // stack 2 push function:
        void push2(int num)
        {
            if((top2-top1) > 1)
            {
                // since this is the push function for stack 2 the top pointer for it will be decremented & then 
                // we'll insert an element because movement is from right to left.
                top2--;
                arr[top2] = num;
            }
            else
                cout<< "Stack overflow" <<endl;
        }

        // stack 1 pop function:
        int pop1()
        {
            // since we are popping from stack 1 , we have to be sure that there is an element in stack 1 & since 
            // our top pointer for stack 1 was initially -1 , that means it should be greater than equal to 0 (the
            // n only an element got inserted).
            if(top1 >= 0)
            {
                int topOfStack1 = arr[top1];
                top1--;

                // return the topmost element
                return topOfStack1;
            }
            // else return -1
            return -1;
        }

        // stack 2 pop function:
        int pop2()
        {
            // since we are popping from stack 2 , we have to be sure that there is an element in stack 2 & since 
            // our top pointer for stack 2 was initially equal to size of array , that means it should be lesser 
            // than the size of array then only an element got inserted).
            if(top2 < size)
            {
                int topOfStack2 = arr[top2];
                top2--;

                // return the topmost element
                return topOfStack2;
            }
            // else return -1
            return -1;
        }


    

};