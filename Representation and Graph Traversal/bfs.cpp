#include<bits/stdc++.h>
using namespace std ;

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

    // BFS  ->  TC -> O(Nodes + 2*Edges)   SC -> O(N+N+N) (visited + adjaceny list +queue) ; 
    // Nodes+2*Edges  as we traverse all the adjacent nodes in undirected graph   

    printf("Enter the root for  traversal ") ;
    int root ;
    cin>>root ;

    queue<int>q ;
    vector<int>vis(n+1,0) ;
    q.push(root) ;
    vis[root] = 1 ;
    

    while( !q.empty()){

        int node = q.front();
        cout<<node<<" ";
        q.pop() ;

        for( auto num : adj[node]){

           if(!vis[num]){
            q.push(num) ;
            vis[num] = 1 ;
           } 

        }
    }

    return 0 ;
}