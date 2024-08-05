#include<bits/stdc++.h>

using namespace std ;

//TC ->  O(N+2E)  -> N = no. of nodes and E = 2E is for total degrees as we traverse all adjacent nodes.
// In the case of connected components of a graph, it will take another O(N) time.

// Space Complexity: O(N) + O(N) ~ O(N), Space for queue data structure and visited array.


bool bfs(int root, vector<int>&vis, vector<int>adj[] ){

    queue<pair<int,int>>q ;  // pair<node,parent>

    q.push({root,-1}) ;
    vis[root] = 1 ;

    while(!q.empty()){

        int node = q.front().first ;
        int parent = q.front().second ;
        q.pop() ;

        for( int adjNode : adj[node]){

            if(!vis[adjNode]){
                vis[adjNode] = 1; 
                q.push({adjNode,node}) ;
            }
            else if( adjNode != parent){
                return true ;
            }
        }
    }
     return  false  ;     

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

            if(bfs(i,vis,adj)){  cout<<"Cycle is present"<<endl ; break ;}
        }
    }

    if( i == N+1){
        cout<<"Cycle is not present"<<endl ;
    }

    
    return 0 ;
}