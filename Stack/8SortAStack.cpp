#include<iostream>
using namespace std;
#include<stack>

// when we have to sort a stack, first we have to get all the elements of the stack out and then we have to re push
// them but this time ensuring that they get inserted in sorted order.
void sortedInsert(stack<int> &s, int num)
{
    if(s.empty()||(s.top()<num))
    {
        s.push(num);
        return;
    }
    int top = s.top();
    s.pop();
    sortedInsert(s,num);
    s.push(top);
}
void sort(stack<int> &s)
{
    if(s.empty())
    {
        return;
    }
    int top = s.top();
    s.pop();
    // once we get all elements out, then our return statement will get back to the line where sort was called,
    // after that we call another fnc , wherein we will be placing the elements back in sorted order.
    sort(s);
    sortedInsert(s,top);

}
int main()
{
    stack<int> s;
    s.push(1);
    s.push(5);
    s.push(2);
    s.push(9);
    sort(s);
    while(!s.empty())
    {
        cout<<s.top()<<",";
        s.pop();
    }

}