#include<iostream> 
#include<stack>
using namespace std;
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
int main()
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    
    int val = 5;
    int cnt = 0;
    insertAtBottom(s,s.size(),val,cnt);
    while(!s.empty())
    {
        cout<<s.top()<<",";
        s.pop();
    }
}