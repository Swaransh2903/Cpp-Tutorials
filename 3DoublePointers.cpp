#include<bits/stdc++.h>
using namespace std;

void update(int **p2)
{
    p2 = p2 + 1; // kuch update hoga -> nhi 
    *p2 = *p2 +1; // kuch update hoga -> haa
    **p2 = **p2+1; // kuch update hoga -> haa

}
int main()
{
    int num=6;
    int *ptr = &num;
    int **ptr2 = &ptr;

    // If num is mapped to 710 then ptr will contain 710 , & if ptr is mapped to 820 then ptr2 will contain 820

    cout<<"ptr is"<<ptr<<endl;
    cout<<"ptr is"<<*ptr2<<endl;
    cout<<"address of ptr is"<<&ptr<<endl;

    // if I want value of num:
    cout<<num<<endl;
    cout<<*ptr<<endl;
    cout<<**ptr2<<endl;

    update(p2);
}

