
//STEPS
//  find Topological using DFS/Kah's algorithm
//  relax the vertices with minimum distance

// there is no topological order for directed cyclic graph so we use Dijakstras for finding the shortest which has large complexity than this method
// there graph is DAG then this algorithm is best

// TC-> O(V+E) {topological sort} + O(V+E) {for relaxation of vertices,} ~ O(V+E).
//SC ->:  O( N) {for the stackt} + O(N) {for storing the shortest distance for each node} + O(N) {for the visited array} + O( N+2M) {for the adjacency list} ~ O(N+M) .


#include<bits/stdc++.h>
using namespace std ;

void dfs(int node, vector< pair<int,int> >adj[],vector<int>&vis, stack<int>&st)
{
    vis[node] = 1 ;

    for( auto it : adj[node]){
        int adjNode = it.first;
        if(!vis[adjNode]){
            dfs(adjNode, adj, vis, st) ;
        }
    }
    st.push(node) ;
}


int main(){

    int V,E ;
    cin>>V>>E ;
    vector< pair<int,int> >adj[V] ;

    for( int i=0 ; i < E ; i++){
        int u,v,w ;
        cin>>u>>v>>w ;
        adj[u].push_back({v,w}) ;
    }

    // finding topological order

    vector<int>vis(V,0) ;
    stack<int>st ;
    for( int i=0 ; i < V ; i++){
        if(!vis[i]){
            dfs(i, adj, vis,st ) ;
        }
    }

    // relaxation with minimum distanc

    int src = 0 ;
    vector<int>dis(V,1e9) ;
    dis[src] = 0;

    while(!st.empty()){
        int node = st.top() ;
        st.pop() ;

        for( auto it : adj[node]){
            int adjNode = it.first ;
            int wt = it.second ;
            if( dis[node] + wt < dis[adjNode] ){
                dis[adjNode] = dis[node]+wt ;
            }
        }
    }

    for( int i= 0 ; i < V ; i++){
        if( dis[i] == 1e9){
            dis[i] = -1 ;
        }
        cout<<dis[i]<<" " ;

    }

    return 0 ;
}