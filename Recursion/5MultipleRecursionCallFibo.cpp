#include<bits/stdc++.h>
using namespace std;
int f(int n)
{
    if(n <= 1)
        return n;
    int last = f(n-1);
    int slast = f(n-2);
    return slast + slast;
}
int main()
{
    int n = 5;
    cout<<f(n);
}