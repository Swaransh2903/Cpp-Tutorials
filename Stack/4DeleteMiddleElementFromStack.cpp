//  #include<iostream>
// #include<stack>
// using namespace std;

// //  Brute Approach : Find the number of elements in stack and then suppose there are n elements in stack then pop
// // first n/2 elements and store them in a separate stack and then remove the middle element and push the stored
// // elements again.
// int main()
// {
//     stack<int> s;
//     s.push(1);
//     s.push(2);
//     s.push(3);
//     s.push(4);
//     s.push(5);

//     int n = s.size();
//     int m = n/2;
//     int cnt = 0;
//     stack<int> saved;
//     while(cnt != m)
//     {
//         int top = s.top();
//         s.pop();
//         saved.push(top);
//         cnt++; 
//     }
//     s.pop();
//     while(!saved.empty())
//     {
//         s.push(saved.top());
//         saved.pop();
//     }

//     while(!s.empty())
//     {
//         cout<<s.top()<<" ";
//         s.pop();
//     }

// }

// Optimized : We can use recursion wherein at every iteration we'll be popping the top element(store in a variable)
// and as soon as we hit the base case, we pop the middle element and then while going back we push the popped 
// element we had stored in a separate variable.

#include<iostream> 
#include<stack>
using namespace std;
void solve(stack<int> &s, int count, int size)
{
    if(count == size/2)
    {
        s.pop();
        return;
    }
    int top = s.top();
    s.pop();
    solve(s,count++,size);
    s.push(top);
    
}
int main();
{
    stack<int> s;
    int count = 0;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    solve(s,count,s.size());
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
}