#include<iostream>
#include<stack>
using namespace std;

// How to approach this problem? Basically in order to reverse the stack, it is first essential to reach the bottom
// of the stack , once we are there at the bottom  of the stack we can apply the insertAtBottom code to push elements
// one by one at the bottom.
void insertAtBottom(stack<int> &s, int size,int val,int cnt)
{
    if(cnt == s.size())
    {
        s.push(val);
        return;
    }
    int top = s.top();
    s.pop();
    insertAtBottom(s,size,val,cnt++);
    s.push(top);

}
void reverse(stack<int>& s, int size)
{
    if(size == 0)
    {
        return;
    }
    int top = s.top();
    s.pop();
    reverse(s,size-1);
    // reverse(s,size--);
    insertAtBottom(s,s.size(),top,0);
}
int main()
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    reverse(s,s.size());
    while(!s.empty())
    {
        cout<<s.top()<<",";
        s.pop();
    }
}