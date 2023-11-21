#include<bits/stdc++.h>
using namespace std;
int main()
{
    int *arr = new int[n];
    // multiple int type ke blocks laata hu jiska address arr me stored hai 

    // ab jb hm 2d array ki baat kr rhe toh hme multiple rows chiye jha fixed no of columns hai yaani bhut saari a
    // array aur un bhut saari array ke pointers(1d array ke concept ko extend krke):
    int **arr = new int* [n];//yha pe sirf pointers banne

    // array bnae:
    for(int i=0;i<n;i++)
    {
        arr[i]=new int[n];
    }

    //values daale:
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>arr[i][j]<<" ";
        }
    }    

    // diff row and col:
    cin>>row;
    cin>>col;

    int **arr=new int*[row];
    for(int i=0;i<row;i++)
    {
        arr[i]=new int[col];
    }
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            cin>>arr[i][j]<<" ";
        }
    }

    // Memory release:
    for(int i=0;i<row;i++)
    {
        delete []arr[i];
    }

    delete []arr;
}