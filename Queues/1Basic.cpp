// Queue follows first in first out principle wherein the element inserted first gets popped out first. We 
// generally implement queues in arrays using two pointers -> front(wherein we pop the element) and rear(wherein
// we push the element.)

// In STL also, there are 2 pointers like q.front() and q.back() , which will give us the 1st and last element in 
// queue respectively.

#include<iostream>
using namespace std;
#include<queue>
int main()
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);

    cout<<q.size()<<endl;

    q.pop();
    cout<<q.size()<<endl;

    cout<<q.empty()<<endl;

    cout<<q.front()<<","<<q.back()<<endl;
}