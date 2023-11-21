//  Parametrized Recursion code to print sum of first n numbers:

#include<bits/stdc++.h>
using namespace std;
void f(int n, int sum)
{
    if(n == 0)
    {
        cout<<sum;
        return;
    }
    f(n-1,sum+n);
}
int main()
{
    int n = 3;
    int sum = 0;
    f(n,sum); 
}

// Functional Recursion code to print sum of first n numbers:

#include<bits/stdc++.h>
using namespace std;
int f(int n)
{
    if(n == 0)
        return 0;
    return n + f(n-1);
}
int main()
{
    int n = 3;
    cout<<f(n);
}