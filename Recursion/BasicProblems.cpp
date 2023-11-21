// print name n times

#include<bits.stdc++.h>
using namespace std;
void f(int i, int n)
{
    if(i>n)
        return;
    cout<<"Swaransh";
    f(i+1,n);
}
int main()
{
    int n;
    cin>>n;
    f(1,n);
}

// print linearly from 1 to n:

#include<bits.stdc++.h>
using namespace std;
void f(int i, int n)
{
    if(i>n)
        return;
    cout<<i;
    f(i+1,n);
}
int main()
{
    int n;
    cin>>n;
    f(1,n);
}