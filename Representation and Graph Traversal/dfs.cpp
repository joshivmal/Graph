#include<bits/stdc++.h>
using namespace std ;


void dfs( int root, vector<int>adj[], vector<int>&vis ){

    if(vis[root])  return ;

    cout<<root<<" " ;

    vis[root] = 1 ;

    for( int num : adj[root]){
        dfs(num,adj,vis) ;
    }
}

int main(){

    int n , m ;
    cin>>n>>m ;

    vector<int>adj[n+1] ;

    for( int i=0 ; i < m ; i++){
        int u, v ;
        cin>>u>>v ;
        adj[u].push_back(v) ;
        adj[v].push_back(u) ;
    }

    // DFS  ->  TC -> O(Nodes + 2*Edges)   SC -> O(N+N) (adjaceny list +stack space) ; 
    // Nodes+2*Edges  as we traverse all the adjacent nodes in undirected graph   

    printf("Enter the root for  traversal ") ;
    int root ;
    cin>>root ;

    vector<int>vis(n+1,0) ;

    dfs(root, adj, vis) ;
    


    return 0 ;
}