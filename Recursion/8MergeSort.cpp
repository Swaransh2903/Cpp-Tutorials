#include<bits/stdc++.h>
using namespace std;
void merge(int l,int arr[],int mid,int r)
{
    int arr1[mid-l+1];
    int arr2[r-mid];
    for(int i = 0; i < mid-l+1; i++)
    {
        arr1[i] = arr[l+i];
    }
    for(int j = 0; j < r-mid; j++)
    {
        arr2[j] = arr[mid+1+j];
    }
    int k = l,m = 0,n = 0;
    int size1 = mid-l+1;
    int size2 = r-mid;
    while(m < size1 && n < size2)
    {
        if(arr1[m] <= arr2[n])
        {
            arr[k] = arr1[m];
            m++;
        }
        else
        {
            arr[k] = arr2[n];
            n++;
        }
        k++;
    }
    while(m < size1)
    {
        arr[k] = arr1[m];
        k++;
        m++;
    }
    while(n < size2)
    {
        arr[k] = arr2[n];
        k++;
        n++;
    }
    return;
} 
void mergeSort(int l,int arr[],int r)
{
    if(l < r)
    {
        int mid = (l+r)/2;
        mergeSort(l,arr,mid);
        mergeSort(mid+1,arr,r);
        merge(l,arr,mid,r);
    }
    return;
}
int main()
{
    int arr[] = {5,6,4,3,7};
    int n = 5;
    mergeSort(0,arr,n-1);
    for(int i = 0; i < n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}