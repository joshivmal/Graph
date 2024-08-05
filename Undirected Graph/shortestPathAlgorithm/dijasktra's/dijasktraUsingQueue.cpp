 //TC ->   O( (V^2 )  insertion and deletion in queue in takes O(1) for N times and O(N) for relaxation
//SC ->  O( V+E)
 
 #include<bits/stdc++.h>
using namespace std ;
int main(){

    int V, E ;
    cin>>V>>E ;

    vector< pair<int,int> >adj[V] ;

    for( int i=0 ; i < E ; i++){
        int u,v,w ;
        cin>>u>>v>>w ;
        adj[u].push_back({v,w}) ;
        adj[v].push_back({u,w}) ;
    }

    int src = 0 ;
    queue<int>q ;
    q.push(src) ;
    vector<int>dis(V,1e9) ;
    dis[src] = 0 ;

    while(!q.empty()){
        int node = q.front() ;
        q.pop() ;
        for( auto it : adj[node]){
            int adjNode = it.first ;
            int w = it.second ;
            if( w+dis[node] < dis[adjNode] ){
                dis[adjNode] = w+dis[node] ; 
                q.push(adjNode) ;
            }
        }
    }

    for( int i=0 ; i < V ; i++){
        cout<<dis[i]<<" " ;
    } 

    return  0 ;
}