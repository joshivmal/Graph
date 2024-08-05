#include<bits/stdc++.h>

using namespace std ;

//TC ->  O(N+2E)  -> N = no. of nodes and E = 2E is for total degrees as we traverse all adjacent nodes.
// In the case of connected components of a graph, it will take another O(N) time.

// Space Complexity: O(N) + O(N) ~ O(N), Space for stack data structure and visited array.


bool dfs(int root, int parent,vector<int>&vis, vector<int>adj[] ){

    vis[root] = 1 ;

    for(int adjNode : adj[root]){

        if(!vis[adjNode]){
            if(dfs(adjNode,root,vis,adj)) return true ;
        }
        else if( adjNode != parent){
            return true ;
        }
    } 
    return false ;
}

int main(){

    int N,E ;  // nodes // edges
    cin>>N>>E ;

    vector<int>adj[N+1] ;

    for( int i=0 ; i<E ; i++){
        int u ,v ;
        cin>>u>>v ;   // nodes where edge is present 
        adj[u].push_back(v);
        adj[v].push_back(u);
    }


    vector<int>vis(N+1,0) ;

    int i = 0 ;
    for( i=0 ; i<=N ; i++){

        if(!vis[i]){

            if(dfs(i,-1,vis,adj)){  cout<<"Cycle is present"<<endl ; break ;}
        }
    }

    if( i == N+1){
        cout<<"Cycle is not present"<<endl ;
    }

    
    return 0 ;
}