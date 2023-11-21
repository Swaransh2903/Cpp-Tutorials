#include<iostream> 
#include<stack>
using namespace std;
int main()
{
    string str = "swaransh";
    stack<int> s;
    string ans = "";
    for(int i=0;i<str.size();i++)
    {
        s.push(str[i]);
    }
    while(!s.empty())
    {
        ans += s.top();
        s.pop();
    }
    cout<<ans;
}