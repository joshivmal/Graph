#include<bits/stdc++.h>
using namespace std ;

int main(){

    // directed graph 
        // 2D matrix 

            // int n ;   // enter the vertices/ nodes
            // printf("Enter the number of nodes ")  ;
            // cin>>n ;

            // vector<vector<int>>arr(n+1,vector<int>(n+1,0)) ;

            // int edge ;   // enter the number of edges
            // printf("Enter the number of edges ")  ;
            // cin>>edge ;

            // for(int i=0 ; i < edge ; i++){
            //     int u, v ;        // enter the nodes where edge is present
            //     cin>>u>>v ;
            //     arr[u][v] = 1 ;
            //     arr[v][u] = 1 ;
            // }

            // for( int i=0 ; i <= n ; i++){
            //     for( int j=0 ; j <= n ; j++){
            //         cout<<arr[i][j]<<" ";
            //     }
            //     cout<<endl ;
            // }

        // adjacency list

            //  int n ;   // enter the vertices/nodes
            // printf("Enter the number of nodes ")  ;
            // cin>>n ;
            // vector<int>adj[n+1] ;

            // int edge ;   // enter the number of edges
            // printf("Enter the number of edges ")  ;
            // cin>>edge ;

            // for( int i=0 ; i < edge ; i++){
            //     int u, v ;        // enter the nodes where edge is present
            //     cin>>u>>v ;
            //     adj[u].push_back(v) ;
            //     adj[v].push_back(u) ;
            // }
            // int j = 0 ;
            // for( int i=0 ; i <= n ; i++){
            //     cout<<i<<" -> ";
            //     for( int j=0 ; j < adj[i].size() ; j++){
            //         cout<<adj[i][j]<<" ";
            //     }
            //     cout<<endl ;
            // }

        // adjacency list  for weightesd graph

        int n, m ;
        cin>>n>>m ;
        vector<pair<int,int>>adj[n+1] ;

        for( int i=0 ; i < m ; i++){
            int u, v , w ;
            cin>>u>>v>>w ;
            adj[u].push_back({v,w}) ;
            adj[v].push_back({u,w}) ;

        }


        return  0;
}