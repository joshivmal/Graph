#include<bits/stdc++.h>   //TC = O(V+V+V)     vis,dfsVis,stack
using namespace std ;      // SC = O(V+E)     nodes and edges

bool dfs(int node, vector<int>adj[],int vis[],int dfsVis[]){
    vis[node] = 1 ;
    dfsVis[node] = 1 ;  // so we can check we are not in a same path

    for( int adjNode : adj[node]){
        if(!vis[adjNode]){
            if(dfs(adjNode,adj,vis,dfsVis)){  return true ;} 
        }
        else if( dfsVis[adjNode]){
            return true ;
        }
    }
    dfsVis[node] = 0 ;
    return false ;
}

int main(){

    int V, E ;
    cin>>V>>E ;

    vector<int>adj[V] ;

    for(int i=0 ; i < E ; i++){
        int u, v ; 
        cin>>u>>v ;
        adj[u].push_back(v) ;
    }

    int vis[V]  = {0};
    int dfsVis[V]  = {0};

    int i = 0 ;
    for( i=0 ; i < V ; i++){
        if(!vis[i]){
            if(dfs(i,adj,vis,dfsVis)){
                cout<<"yes it has cycle"<<endl ;
                cout<<i<<endl ;
                break ;
            } 
        }
    }
    if( i > V){
        cout<<"no cycle "<<endl ;
    }
    return 0 ;
}