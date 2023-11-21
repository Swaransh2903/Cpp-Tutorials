#include<iostream>
#include<stack>
#include<vector>
using namespace std;
// void nextSmallerElement(int *arr,vector<int>& next)
// {
//     stack<int> s;
//     for(int i=0;i<n;i++)
// }
// int largestAreaHistogram(int *arr,int n)
// {
//     vector<int> next(arr.size());
//     vector<int> prev(arr.size());
//     nextSmallerElement(arr,next);
//     prevSmallerElement(arr,prev);
//     for(int i=0;i<n;i++)
//     {

//     }
// }
int main()
{
    stack<int> s;

    int arr[4][4] = {{0,1,1,0},{1,1,1,1},{1,1,1,1},{1,1,0,0}};
    
    // int n = arr.size();
    // int m = arr[0].size();
    
    // cout<<n<<" "<<m<<endl;
    int area = largestAreaHistogram(arr[0],n);
    for(int i=1;i<4;i++)
    {
        for(int j=1;j<4;j++)
        {
            if(arr[i][j]!=0)
                arr[i][j] = arr[i][j]+arr[i][j-1];
        }
        area = max(area,largestAreaHistogram(arr,n));
    }

    cout<<"The maximum area is : "<<area;

    // s.push(1);
    // s.push(2);
    // s.push(3);
    // s.push(4);
    // s.push(5);
}