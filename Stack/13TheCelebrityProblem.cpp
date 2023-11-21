// What is the celebrity problem: A celebrity is a person who is known to everyone but knows no one. We are given
// a 2D array and we've to find out if there exists a celebrity in the list of members or not.



// #include<iostream>
// #include<stack>
// using namespace std;
// int main()
// {
//     // Now let's take this example. The indices of the 2D array can be treated as people(0,1,2) and from the 
//     // array data, we can see that person '1' is known by both '0' (arr[0][1]=1) & '2' (arr[2][1]=1) and '1'
//     // doesn't know anybody. Therefore '1' is a celebrity.
//     int arr[3][3] = {{0,1,0},{0,0,0},{0,1,0}};

//     int n = 3,celebrity=-1;
//     // Brute Force :  We know that when we do arr[i][j], the value of arr[i][j] would tell whether i knows j or not
//     // and value of arr[j][i] would tell whether j knows i or not. Let's say we are at index '0' , if we assume 
//     // that '0' is a celebrity , then the row corresponding to '0' would have all 0's because a celebrity should
//     // know no one and the column corresponding to '0' should have all 1's except arr[0][0] because everyone 
//     // should know a celebrity. So like this we'll be doing for all array indices (the outer loop will mean 
//     // traversing for each array index and the inner loop will involve comparing the current index with every other
//     // index in order to determine whether the current index is a celebrity or not).These loops combinedly make the 
//     // TC O(n^2).

//     int flag=0;
//     for(int i=0;i<3;i++)
//     {
//         int rowCnt=0,colCnt=0;
//         for(int j=0;j<3;j++)
//         {
//             if(arr[i][j]==0)
//                 rowCnt++;
//             if(arr[j][i]==1)
//                 colCnt++; 
//         }
//         if(rowCnt==n && colCnt==n-1)
//         {
//             celebrity = i;
//             flag=1;
//             break;
//         }
//     }
//     if(flag==1)
//         cout<<"Celebrity is: "<<celebrity;
//     else 
//         cout<<"No celebrity"<<-1;

//     // for(int i=0;i<3;i++)
//     // {
//     //     for(int j=0;j<3;j++)
//     //         cout<<arr[i][j]<<" ";
//     //     cout<<endl;
//     // }

// }

// Optimized Approach: What we know is that the max count of celebrity can only be 1 in the problem. We can utilize
// this in order to use a stack based approach . Let's say we push all elements into the stack and at a time we 
// pop the top 2 elements from the stack. Let's say the elements that we popped out were 'a' & 'b'. Now since we
// know that a celebrity should be known by everyone and should know nobody , if we find out that a knows b then
// we'll not push (a) back because if 'a' was a celebrity he should've not known anyone , but 'b' can be a potential
// candidate for a celebrity because 'b' is already known by 'a' and can be known by rest of the elements in the 
// stack. Otherwise, we'll push (a) because if 'b' was a celebrity he should've been known by everyone which is 
// not the case here. TC : O(n).

#include<iostream>
#include<stack>
using namespace std;
bool knows(int a,int b,int arr[][3])
{
    return (arr[a][b]==1) ? 1:0;

}
int main()
{
    stack<int> s;
    int arr[3][3] = {{0,1,0},{0,0,0},{0,1,0}};
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
            s.push(arr[i][j]);
    }
    while(s.size()>1)
    {
        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();
        if(knows(a,b,arr))
            s.push(b);
        else
            s.push(a);
    }

    int num = s.top();
    int rowCnt=0,colCnt=0;
    for(int i=0;i<3;i++)
    {
        if(arr[num][i]==0)
            rowCnt++;
        if(arr[i][num]==1)
            colCnt++;

    }
    if(rowCnt==3&&colCnt==2)
        cout<<"Celebrity is: "<<num;
    else
        cout<<"No celebrity";
}