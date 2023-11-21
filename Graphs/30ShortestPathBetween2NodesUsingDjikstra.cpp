

#include<stdio.h>
using namespace std;
int main()
{
    int e,n;
    cin>>e>>n;
    vector<pair<int,int>> adj[n];

    for(int i = 0;i < e;i++)
    {
        int u,v,edgeWt;
        cin>>u>>v>>edgeWt;
        adj[u].push_back({v,edgeWt});
        adj[v].push_back({u,edgeWt});
    }

    vector<pair<int,int>> distParent[n];
    for(int i = 0;i < n;i++)
    {
        distParent[i].first = i;
        distParent[i].second = INT_MAX;
    }

    int src,destination;
    cin>>src>>destination;
    distParent[src].second = 0;

    set<pair<int,int>> st;
    st.insert({0,src});

    while(!st.empty())
    {
        auto it1 = *(st.begin());
        int distanceOfCurrFromSrcNode = it1.first;
        int node = it1.second;
        st.erase(it1);

        for(auto it:adj[node])
        {
            int distanceOfNextNodeFromCurrNode = it.second;
            int nextNode = it.first;
            if((distanceOfCurrFromSrcNode+distanceOfNextNodeFromCurrNode) < distParent[nextNode].second)
            {
                if(distParent[nextNode].second != INT_MAX)
                    st.erase({distParent[nextNode].second,nextNode});
                distParent[nextNode].second = distanceOfCurrFromSrcNode+distanceOfNextNodeFromCurrNode;
                distParent[nextNode].first = node;
                st.insert({distParent[nextNode].second,nextNode});
            }
        }
    }
    vector<int> ans;
    if(distParent[destination] == destination)
        return ans;
    else
    {
        ans.push_back(destination);
        while(distParent[destination].first != destination)
        {
            ans.push_back(distParent[destination].first);
            destination = distParent[destination].first;
        }
        ans.push_back(src);
    }
    reverse(ans.begin(),ans.end());
    return ans;
}