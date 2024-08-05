/* topolocial sort is that sort  where if there is a edge between u->v  then u always comes first in order 
 we can do toposort only for DAG (directed acyclic graph) reason 
    -> 1 : if there is undirected graph and there is edge b/w  u-v, then we are not able to define who will come first
    -> 2 : if there is cyclic graph a->b, b->c, c->a then we are not able to define who will come first in a, b and c
Application: project scheduling : we cannot do project before proper planning, or we cannot wear socks after wering shoes, means sequencial task


*/


#include<bits/stdc++.h>    // TC = : O(V+E)+O(V), where V = nodes and E = edges. There can be at most V components. So, another O(V) time complexity.
using namespace std ;      // SC = O(V+V+V)  vis, stack, ans

void dfs(int node, stack<int>&st, int vis[], vector<int>adj[]){

    vis[node] = 1 ;

    for( int adjNode : adj[node]){
        if(!vis[adjNode] ) {
            dfs(adjNode, st, vis, adj) ; 
        }
    }
    st.push(node) ;
}


void topoSort(int V, vector<int>adj[]){

    int vis[V] = {0} ;
    stack<int>st; 
    for( int i=0 ; i < V ; i++){
        if( !vis[i]) dfs(i, st, vis, adj) ;
    }

    vector<int>ans ;

    while(!st.empty()){

        cout<<st.top()<<" " ;
        ans.push_back(st.top()) ;
        st.pop() ;
    }

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