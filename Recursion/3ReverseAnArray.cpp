// #include<bits/stdc++.h>
// using namespace std;
// void f(int start,int arr[],int end)
// {
//     if((start>end) || (start == end))
//         return;
//     swap(arr[start],arr[end]);
//     f(start+1,arr,end-1);
// }
// int main()
// {
//     int arr[] = {1,2,3,4,5};
//     int size = 5;
//     f(0,arr,size);
//     for(int i = 0;i < size;i++)
//         cout<<arr[i]<<" ";
// }

// Using a single variable:

#include<bits/stdc++.h>
void swap(int& a, int& b)
{
    int temp =  a;
    a = b;
    b = temp;
    return;
}
using namespace std;
void f(int i,int arr[],int n)
{
    if(i>=n/2)
        return;
    swap(arr[i],arr[n-i-1]);
    f(i+1,arr,n);
}
int main()
{
    int arr[] = {1,2,3,4,5};
    int size = 5,i=0;
    f(0,arr,size);
    for(int j = 0;j < size;j++)
        cout<<arr[j]<<" ";

}