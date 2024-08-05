#include<bits/stdc++.h>
#define  pi pair<int,int> 

//TC ->   O( (V+E)logV ),    VlogV for insertion in Pq and ElogV for edge relaxation 
//SC ->  O( V+E)


using namespace std ;
int main(){

    int V,E ;
    cin>>V>>E ;

    vector< vector<int> >adj[V] ;

    for( int i=0 ; i < E ; i++){
        int u,v,w ;
        cin>>u>>v>>w ;
        adj[u].push_back({v,w}) ;
        adj[v].push_back({u,w}) ;
    }

    priority_queue<pi,vector<pi>, greater<pi> >pq ;

    vector<int>dis(V,1e9) ;
    int src = 0 ;
    dis[src] = 0 ;
    pq.push({0,src}) ;    //dist,source

    while(!pq.empty())
    {

        int dist = pq.top().first ;
        int node = pq.top().second ;
        pq.pop() ;

        for( auto it :  adj[node]){

            int adjNode = it[0] ;
            int wt = it[1];

            if(dist+wt < dis[adjNode]){

                dis[adjNode] = dist+wt ;
                pq.push({dist+wt,adjNode}) ;
            }
   
        }
    }

    for( int i=0 ; i < V ; i++){
        cout<<dis[i]<<" ";
    }


    return 0; 
}