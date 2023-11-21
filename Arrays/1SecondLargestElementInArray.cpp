// A data structure consisting of homogeneous elements. The size of an array is fixed.
// By default array gets initialized with garbage values.
// But if we declare array outside main(global variable) -> all elements are assigned 0 value

// If I declare array globally: max size = 10^7, if I declare locally(inside main or any function) : max size = 10^6

// Array elements are stored in contiguous memory location.

// largest element in array:

// For this question , we go forward with the brute one first:

#include<iostream>
using namespace std;
int main()
{
    int arr[5] = {7,1,9,2,4};

    // applying any sort technique -> minimum tc o(nlogn)

    // we know that if we sort in ascending order then last element will be largest
}

// optimal:

#include<iostream>
using namespace std;
int main()
{
    //  O(N)
    int arr[5] = {7,1,9,2,4};

    int largest = arr[0];
    for(int i = 1;i < 5;i++)
    {
        largest = max(largest,arr[i]);
    }
    return largest;
}

// second largest:

#include<iostream>
using namespace std;
int main()
{
    int arr[5] = {7,1,9,2,4};

    // applying any sort technique -> minimum tc o(nlogn)

    // we know that if we sort in ascending order then last element will be largest and then if we traverse in reverse
    // order and then till the element remains equal to the largest , we'll be decrementing i and as soon as we 
    // get an element not equal to the last we break out from the loop and print it because since the array is in
    // sorted order this will definitely be the second largest -> in worst case - O(N).
}


// better:

#include<iostream>
using namespace std;
int main()
{
    // O(N)
    int arr[5] = {7,1,9,2,4}
    int largest = arr[0];

    for(int i = 1;i < 5;i++)
        largest = max(largest,arr[i]);
    
    // O(N)
    int secondLargest = -1;
    
    for(int i = 0;i < 5;i++)
    {
        if(secondLargest < arr[i] && arr[i] != largest)
            secondLargest = arr[i];
    }
    return (secondLargest == -1)?arr[0]:secondLargest;
}

// optimal:

#include<iostream>
using namespace std;
int main()
{
    // O(N)
    int arr[5] = {7,1,9,2,4};
    int largest = arr[0];
    int secondLargest = -1;

    // This is the most optimal wherein we try to get the largest as well as second largest element simultaneously.
    // We have initialized largest with arr[0] and secondlargest with -1 and everytime we get any element greater
    // than the largest value we replace largest with it and naturally the second largest will be assigned with
    // the previous value of largest because all the elements prior to one we encountered now(where arr[i] > largest)
    // would've been smaller than previous value of largest.
    // There can also be a scenario wherein we encounter an element which was not greater than the current largest
    // but greater than the current second largest and in that case we'll update the second largest value with it.
    for(int i = 1;i < 5;i++)
    {
        if(arr[i] > largest)
        {
            secondLargest = largest;
            largest = arr[i];
        }
        else if(arr[i] < largest && arr[i] > secondLargest)
            secondLargest = arr[i];
    }
    
}