
#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> iPair;



void dijsktra(int n, vector<vector<int>> input , int source)
{
    //adjacency list , pair(vertex,distance)
    vector<vector<iPair>>adj_list(n,vector<iPair>(0));

    //initially assign he distance vector to INT_MAX

    vector<int>dist(n,INT_MAX);
    // define he priority queue to hold the min distance nodes
    // make_pair(distance,destination)
    priority_queue<iPair,vector<iPair>, greater<iPair>>q;

    for(auto e:input)
    {

        //source,pair(vertex,distance)
        adj_list[e[0]].push_back(make_pair(e[1],e[2]));
        adj_list[e[1]].push_back(make_pair(e[0],e[2]));
    }
    //push the source element to the array
    q.push(make_pair(0,source));

    dist[source] = 0;
    while(!q.empty())
    {


        int u = q.top().second;

        q.pop();
        for(auto e:adj_list[u])
        {
            int v = e.first;
            int weight = e.second;
            // since initially the value will be int_max all the adjacent nodes will be chosen
            if (dist[v]>   weight + dist[u] )
            {
                dist[v] = weight + dist[u];
                q.push(make_pair(dist[v],v));
            }
        }
    }

    for(auto d:dist)
        cout << d << " ";

}

// Driver program to test methods of graph class
int main()
{
    vector<vector<int>>input =   {{0, 1, 4}
    ,{0, 7, 8}
    ,{1, 2, 8}
    ,{1, 7, 11}
    ,{2, 3, 7}
    ,{2, 8, 2}
    ,{2, 5, 4}
    ,{3, 4, 9}
    ,{3, 5, 14}
    ,{4, 5, 10}
    ,{5, 6, 2}
    ,{6, 7, 1}
    ,{6, 8, 6}
    ,{7, 8, 7}};
    int source = 0;
    dijsktra(9,input,source);


	return 0;
}




