#include<bits/stdc++.h>
using namespace std ;         //  TC =>   O(V+E)   node+edges
                             // O(V+V)    indegree  + queue

int main(){

    int V, E ;
    cin>>V>>E ;

    vector<int>adj[V] ;

    for(int i=0 ; i < E ; i++){
        int u, v ; 
        cin>>u>>v ;
        adj[u].push_back(v) ;
    }

    int indegree[V] = {0} ;
    int i = 0 ;

    for( i=0 ; i < V ; i++){

        for( int j = 0 ; j < adj[i].size() ; j++){

            indegree[adj[i][j]]++ ;

        }
    }

    queue<int>q;

    for( int i=0 ; i < V ; i++){
        if(indegree[i] == 0){
            q.push(i) ;
        }
    }

    int cntNode = 0 ;

    while(!q.empty()){
        int node = q.front() ;
        q.pop() ;
        cntNode++  ;

        for( int adjNode : adj[node]){
            if( --indegree[adjNode] == 0){
                q.push(adjNode) ;
            }
        }
    }


    if(  cntNode < V){
        cout<<"cycle is present"<<endl ;
    }
    else{
        cout<<"no cycle"<<endl ;
    }
    return 0 ;
}