#include<bits/stdc++.h>
using namespace std; 

// this code is written for unit weight edge

//  TC -> O((V+2E))   ->  V for nodes and 2E for edges
//  SC -> O(V+V+(V+E))  -> O(V+E) -> dis, queue, adjacency list

int main(){

    int V, E ;   // vertices and Edges
    cin>>V>>E ;

    vector<int>adj[V] ;

    for( int i=0 ; i < E ; i++){
        int u,v ;
        cin>>u>>v ;                     // edges b/w nodes
        adj[u].push_back(v) ;
        adj[v].push_back(u) ;
    }

    int src = 0 ;  // source from where you want to find minimum distance for all the nodes of the graph

    queue<int>q ;
    q.push(src) ;
    vector<int>dis(V,1e9) ;
    dis[src] = 0 ;

    while(!q.empty()){
        int node = q.front() ;
        q.pop() ;
        for( int adjNode : adj[node]){
            if(dis[node]+1 < dis[adjNode] ){
                dis[adjNode] = dis[node]+1 ;
                q.push(adjNode) ;
            }
        }
    }

    for( int i=0 ; i < V ; i++){
        if( dis[i] == 1e9){
            dis[i] = -1 ;
        }
    }

    for( int i=0 ; i < V ; i++){   // where distance -1 signifies non reachable node 
        cout<<dis[i]<<" ";
    }

    return 0 ;
}

// this code is written for different weights in the edges  (need to verify for different test cases)
// #include<bits/stdc++.h>
// using namespace std ;
// int main(){

//     int V, E ;
//     cin>>V>>E ;

//     vector< pair<int,int> >adj[V] ;

//     for( int i=0 ; i < E ; i++){
//         int u,v,w ;
//         cin>>u>>v>>w ;
//         adj[u].push_back({v,w}) ;
//         adj[v].push_back({u,w}) ;
//     }

//     int src = 0 ;
//     queue<int>q ;
//     q.push(src) ;
//     vector<int>dis(V,1e9) ;
//     dis[src] = 0 ;

//     while(!q.empty()){
//         int node = q.front() ;
//         q.pop() ;
//         for( auto it : adj[node]){
//             int adjNode = it.first ;
//             int w = it.second ;
//             if( w+dis[node] < dis[adjNode] ){
//                 dis[adjNode] = w+dis[node] ; 
//                 q.push(adjNode) ;
//             }
//         }
//     }

//     for( int i=0 ; i < V ; i++){
//         cout<<dis[i]<<" " ;
//     } 

//     return  0 ;
// }