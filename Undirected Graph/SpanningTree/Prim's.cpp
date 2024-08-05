// Spanning tree -> Tree which has N nodes and N-1 edges and all nodes are reachable to one another
// Minimum spanning tree -> sapnning tree with minimum sum , graph can have multiple MST

// TC -> ElogE(push edge) + ElogE(pop edge) ~ ElogE    (isertion and deletion in pq)
// SC -> E+V  (adjacency list and visited array)

#define pii pair<int,int>
#define ppi pair<int,pair<int,int>>
#include<bits/stdc++.h>
using namespace std ;
int main(){

    // int V,E ;    // vertex and edges
    // cin>>V>>E ;
    // // vector<vector<int>>Edges = {{0, 1, 2}, {0, 2, 1}, {1, 2, 1}, {2, 3, 2}, {3, 4, 1}, {4, 2, 2}} ;
    // vector<vector<int>>adj[V] ;   // adjacency list
    // for( int i=0 ; i < E ; i++){
    //     int u, v, w ;
    //     cin>>u>>v>>w ;
    //     adj[u].push_back({v,w}) ;
    //     adj[v].push_back({u,w}) ;
    // }
    // priority_queue<pii, vector<pii>, greater<pii> >pq ;   // min HEAP
    // vector<int>vis(V,0) ;   // visited array
    // int src = 0 ;    // we can take any source
    // pq.push({0,0}) ;   // (edge weight, Node)
    // long long sum = 0 ;  // sum of minimum spanning tree
   
    // // vis[src] = 1 ;
    // while(!pq.empty()){
    //     auto it = pq.top() ;
    //     pq.pop() ;
    //     int EdgeWeight = it.first ;
    //     int node = it.second ;
    //      if (vis[node] == 1) continue;              // most important line
    //     vis[node] = 1;
    //     sum +=  EdgeWeight ;
    //     for( auto it : adj[node]){
    //         int adjNode = it[0] ;
    //         int edW = it[1] ;
    //         if(!vis[adjNode]){
    //             pq.push({edW,adjNode}) ;
    //         }
    //     }
    // }
    // cout<<"Sum of MST "<<sum<<endl ; 
    //  return 0 ;


    int V,E ;    // vertex and edges
    cin>>V>>E ;
    vector<vector<int>>adj[V] ;   // adjacency list
    for( int i=0 ; i < E ; i++){
        int u, v, w ;
        cin>>u>>v>>w ;
        adj[u].push_back({v,w}) ;
        adj[v].push_back({u,w}) ;
    }
    priority_queue<ppi, vector<ppi>, greater<ppi> >pq ;   // min HEAP
    vector<int>vis(V,0) ;                                // visited array
    int src = 0 ;                                        // we can take any source
    pq.push({0,{0,-1}}) ;                                // (edge weight, Node, parent)
    long long sum = 0 ;                                  // sum of minimum spanning tree
    vector<pair<int,int>>spanningTree ;                  //spanning tree
   
  
    while(!pq.empty()){
        auto it = pq.top() ;
        pq.pop() ;
        int EdgeWeight = it.first ;
        int node = it.second.first ;
        int parent = it.second.second ;
         if (vis[node] == 1) continue;              // most important line
        vis[node] = 1;
        sum +=  EdgeWeight ;
        if( parent != -1 ){ spanningTree.push_back({node,parent}) ;}

        for( auto it : adj[node]){
            int adjNode = it[0] ;
            int edW = it[1] ;
            if(!vis[adjNode]){
                pq.push({edW,{adjNode,node}}) ;
            }
        }
    }

    for( int i=0 ;i < spanningTree.size() ; i++){
        cout<<spanningTree[i].first<<" -> "<<spanningTree[i].second<<endl ;
    }
    cout<<"Sum of MST "<<sum<<endl ; 


     return 0 ;

} 