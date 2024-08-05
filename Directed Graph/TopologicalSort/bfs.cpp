/* topolocial sort is that sort  where if there is a edge between u->v  then u always comes first in order 
 we can do toposort only for DAG (directed acyclic graph) reason 
    -> 1 : if there is undirected graph and there is edge b/w  u-v, then we are not able to define who will come first
    -> 2 : if there is cyclic graph a->b, b->c, c->a then we are not able to define who will come first in a, b and c
Application: project scheduling : we cannot do project before proper planning, or we cannot wear socks after wering shoes, means sequencial task

*/


#include<bits/stdc++.h>   // Kahn's algorithm
using namespace std ;

void bfs( queue<int>&q,  vector<int>adj[], int indegree[],vector<int>&ans){

    while(!q.empty())
    {
        int node = q.front() ;
        q.pop() ;
        cout<<node<<" " ;
        ans.push_back(node) ;

        for( int adjNode : adj[node]){

            if( --indegree[adjNode]  == 0 ) {
                q.push(adjNode) ;
            }
        }
    }
}


void topoSort(int V, vector<int>adj[]){

    int indegree[V] = {0} ;

     for( int i=0 ; i < V ; i++ ){
        for( int j=0 ; j < adj[i].size() ; j++){
            indegree[ adj[i][j] ]++ ;
        }
    }
    queue<int>q ;
    vector<int>ans ;

    for( int i=0 ; i < V ; i++){
        if(indegree[i] == 0){
            q.push(i) ;
        }
    }

    bfs(q,adj,indegree,ans) ;

}

int main(){

    int V,E ;
    cin>>V>>E ;
    vector<int>adj[V] ;

    for( int i=0 ; i < E ; i++){

        int u, v ;
        cin>>u>>v ;
        adj[u].push_back(v);   // directed graph

    }

    topoSort(V,adj) ;

    return 0 ;
}