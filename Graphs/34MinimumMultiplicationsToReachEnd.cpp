// Given start, end and an array arr of n numbers. At each step, start is multiplied with any number in the array
// and then mod operation with 100000 is done to get the new start.Your task is to find the minimum steps in 
// which end can be achieved starting from start. If it is not possible to reach end, then return -1.

// Approach? What does this problem feel like? Like let's say we start from a source and then we'll multiply that
// source with every array index element just to ensure that were we able to get the destination. If no, then we'll
// store the obtained numbers as level 1 values and then we gonna repeat the same process for level 2 , level 3...
// until we get the final answer. At whatever level we were able to get the final answer, it would simply be the
// minimum number of multiplications to reach that because we are using a BFS wherein the level increment is 
// constant across any path we choose.

// The only catch here is what will be the range of values that we will be storing in the distance array because
// this isn't a graph with some predefined size or list of adjacents. So since it has already been stated in the 
// problem that we need to do a modulo 10^5 for the product obtained after multiplication, this modulo 5 will
// conmpress the values > 10^5 to something lesser than 10^5 i.e there could be a possible update in the distance
// array within this index range only: [0,9999]

#include<stdio.h>
using namespace std;
int main()
{
    // consists the list of number to which source can be multiplied
    vector<int> arr;

    // source and destination numbers
    int start,end;
    cin>>start>>end;

    vector<int> dist(10000,1e9);

    queue<pair<int,int>> q;
    // the start node and the steps taken to reach it
    q.push({start,0});

    // start will be at a distance 0 from itself
    dist[start] = 0;

    while(!q.empty())
    {
        int node = q.front().first;
        int steps = q.front().second;
        q.pop();

        // iterating through each array index and multiplying the respective value with the current node to see
        // if we can get the end value.
        for(auto it:arr)
        {
            // compressing the product in a range from [0,9999]
            int prod = (it*node) % 1e5;

            // if the steps taken currently to form that product was less than the previous number of steps, then
            // we update
            if((steps + 1) < dist[prod])
            {
                dist[prod] = steps+1;
                // if we during computing the product , end up getting the end node , we're rest assured then the
                // steps+1 will account to min mulitiplications(as discussed above) and so we directly return it
                // (steps + 1 because we used one additional multiplication step to form that product that was
                // equivalent to the end value)
                if(prod == end)
                    return steps + 1;
                q.push({steps+1,it});
            }
        }
    }
    // if we are not able to form the end value we return -1
    return -1;
}