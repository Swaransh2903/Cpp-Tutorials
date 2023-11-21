// When we are coding quick sort we know that we are basically choosing a pivot element and at every iteration we
// are modifying the array in such a way that every element on the left of pivot is smaller than it and every element
// on the right is greater than equal to it (though the order on the left or right might or might not be sorted).

#include<bits/stdc++.h>
using namespace std;
int partition(int low,int arr[], int high)
{
    //  Now since our main aim in this function is to shift all the smaller elements to the left of pivot and the
    //  greater one's to the right , so first we define 2 pointers one that will start from the leftmost position
    // and one from the rightmost.
    int i = low;
    int j = high;

    // At every iteration we are assuming our pivot to be the first position element.
    int pivot = arr[low];
    
    // If the leftmost position pointer crosses the rightmost , then our array has achieved it's required state
    // and so we'll move out of the loop
    while(i < j)
    {
        // Our objective is to move all the smaller elements to the left , so if our leftmost pointer on incrementing
        // encounters elements that are smaller than the pivots so we simply increment the pointer because they
        // are already positioned to the left, however if we encounter any greater element then we wait because
        // there can be a possibility that as we are moving the pointer starting from the rightmost position backwards, we
        // encounter an element smaller than pivot (note: all the greater elements from the right are ignored for 
        // the same reason we did for the smaller elements on the left) and inspite of being smaller than the pivot
        // it's still at a position which is right to the position of greater element we encountered while moving
        // the left pointer (because j pointer is still ahead of i) and so they need to be swapped.
        while(arr[i] <= pivot && i < high)
            i++;
        while(arr[j] > pivot && j > low)
            j--;
        if(i < j)
            swap(arr[i],arr[j]);
    }
    swap(arr[low],arr[j]);
    // The partition index will be j which is actually the position of the  pivot element in the sorted array.
    return j;
}
void qs(int low,int arr[],int high)
{
    // if the low exceeds the high pointer , that means that we are at a position wherein our first pointer has
    // crossed the last one implying that all elements have been sorted.
    if(low < high)
    {
        int partitionIndex = partition(low,arr,high);
        qs(low,arr,partitionIndex-1);
        qs(partitionIndex+1,arr,high); 
    }
    return;
}
int main()
{
    int n = 5;
    int arr[] = {1,5,3,2,7};
    qs(0,arr,n-1);
    for(int i = 0;i < n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}