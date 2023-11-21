// There are n cities and m edges connected by some number of flights. You are given an array flights where 
// flights[i] = [fromi, toi, pricei] indicates that there is a flight from the city fromi to city toi with cost 
// price i.You are also given three integers src, dst, and k, return the cheapest price from src to dst with 
// at most k stops. If there is no such route, return -1.

#include<stdio.h> 
using namespace std; 
int main()
{
    // Every internal vector consists of 3 indexes: index[0] : the city from where we are flying , index[1]: the 
    // city to which we are flying and index[2]: the cost for the filght
    vector<vector<int>> flights;

    // number of cities
    int n;
    cin>>n;

    //source , destination and max number of stops allowed
    int src,dest,k;
    cin>>src>>dest>>k;

    // since we are given flights in the form of(fromi , toi , i) -> probably we can create a adjacency list in 
    // order to better visualize from which city to which city a path exist

    vector<pair<int,int>> adj[n];
    for(auto it:flights)
    {
        // this time this will be a directed graph because there is a clear indication that we are travelling from
        // a city to another city and not vice versa
        adj[it[0]].push_back({it[1],it[2]});
    } 

    // we take a cost array wherein we assume that all other cities except the source city(which will be reached at cost
    // = 0 from itself) are at maximum distance(cost wise) from the source.
    vector<int> cost(n,INT_MAX);
    cost[src] = 0;


    // Why a normal djikstra will fail wherein we push elements on the basis of sorted order of incurred cost? Because
    // here we have an additional constraint of the number of stops that are allowed so let's suppose that you reached
    // a node from the source via a shorter distance but you consumed more number of stops than stated , then 
    // next time if you reach the same node via a longer distance but stops within the stated limit , it inspite of
    // being a potential candidate for the final answer will not get pushed into the priority queue because we have
    // already updated the distance array with a smaller distance(although it's not correct because therein we used
    // more number of stops than required). So, we can do 2 things : if we follow the distance based priority then
    // we can add a check wherein we only push the distance only when the node is within the number of stops, else
    // we can follow a stop based queue system(we are not taking priority queue because then it will take into 
    // account minimum number of stops (i.e even if we are allowed to take at max 2 stops , then also it will consider
    // the answer with 0 stops due to stop based priority even though the cost incurred might be high)).

    // now since this time we have to find the cheapest flight (somewhat similar to finding the shortest distance) but
    // with an addition of using at most k stops to do so. So this time every value in priority queue can be stored
    // as : pair<int,pair<int,int>> wherein the first (int) : indicates the cost incurred to reach that city from source
    // whereas the second pair can be defined like this : pair.first: is the city we are travelling to and
    // pair.second : indicates how many stops have been taken till now

    priority_queue<pair<int,pair<int,int>> pq;
    pq.push({0,{src,0}});

    // the minCost gets updated everytime we reach the destination via some path with viable number of stops
    int minCost = INT_MAX;
    while(!pq.empty())
    {
        int costOfCurrCityFromSource = pq.top().first;
        int city = pq.top().second.first;
        int stops = pq.top().second.second;
        pq.pop();

        if(city == dest && stops <= k)
            minCost = min(minCost,costOfCurrCityFromSource);
        for(auto it:adj[city])
        {
            int costOfNextCityFromCurrCity = it.second;
            // we are only those stops in the queue which have not surpassed the max stop limit because if in future
            // we encounter we reach that point via lesser number of stops but longer distance it will not get 
            // considered . So our priority is both to get the cheapest flight and also it should not surpass the stop
            // limit.
            if((costOfCurrCityFromSource + costOfNextCityFromCurrCity) < cost[it.first] && stops < k)
            {
                cost[it.first] = costOfCurrCityFromSource + costOfNextCityFromCurrCity;
                if(it.first != dest)
                    pq.push({cost[it.first],{it.first,stops+1}});
                else
                    pq.push({cost[it.first],{it.first,stops}});
            }
        }
    }
    return minCost;
}