/*
Bellman Ford -> speciality -> it handles negative edges and negative cycle while dijasktra's went
 to infinite loop  for negative edges
in atmost cases, it takes n-1 iterations
TC -> O(VE)
SC ->O(V)


*/


#include<bits/stdc++.h>
using namespace std ;
int main(){

    int V,E ;
    cin>>V>>E ;
    vector< vector<int> >Edges ;

    for( int i=0 ; i < E ;i++){
        int u,v,w;
        cin>>u>>v>>w;
        Edges.push_back({u,v,w}) ;
    }

    vector<int>dis(V,1e9) ;
    int src = 0;
    dis[src] = 0 ;

    for( int i=0 ; i < V-1 ; i++){

        for(int i=0 ; i < Edges.size() ; i++){
            
            int u = Edges[i][0] ;
            int v = Edges[i][1] ;
            int w = Edges[i][2] ;

            if( dis[u] != 1e12 && dis[u]+w < dis[v]){
                dis[v] = dis[u]+w ;
            }
        }
    }

    for(int i = 0 ; i < Edges.size() ; i++){
          
            int u = Edges[i][0] ;
            int v = Edges[i][1] ;
            int w = Edges[i][2] ;

            if( dis[u] != 1e12 && dis[u]+w < dis[v]){
                cout<<"It has a negative Cycle"<<endl ;
                break ;
            }
    }

    for( int i=0 ; i < V ; i++){
        cout<<0<<" -> "<<i<<"dis is"<<dis[i]<<endl ;
    }

    return 0;
}