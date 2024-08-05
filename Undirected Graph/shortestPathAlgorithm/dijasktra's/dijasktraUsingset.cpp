#include<bits/stdc++.h>
#define  pi pair<int,int> 

//TC ->   O( (V+E)logV ),    VlogV for insertion in Pq and ElogV for edge relaxation 
//SC ->  O( V+E)

using namespace std ;
int main(){

    int V,E ;
    cin>>V>>E ;

    vector< vector<int> >adj[V] ;

    for( int i=0 ; i < E ; i++){
        int u,v,w ;
        cin>>u>>v>>w ;
        adj[u].push_back({v,w}) ;
        adj[v].push_back({u,w}) ;
    }

    set<pair<int,int>>st ;
    vector<int>dis(V,1e9) ;
    int src = 0 ;
    //cin>>src ;
    dis[src] = 0 ;
    st.insert({0,src}) ;

    while(!st.empty())
    {
        auto it = st.begin() ; 
        int dist = (*it).first ;
        int node = it->second ;
        st.erase(it) ;

        for( auto it :  adj[node]){

            int adjNode = it[0] ;
            int wt = it[1];

            if(dist+wt < dis[adjNode]){

                // erase if it was visited previously at  a greater cost.
                if(dis[adjNode] != 1e9)   //(optional) only for complexity reduction
                    st.erase({dis[adjNode], adjNode});  //
                    
                    // If current distance is smaller,push it into the queue
                    dis[adjNode] = dist + wt; 
            }
        }
    }

    for( int i=0 ; i < V ; i++){
        cout<<dis[i]<<" ";
    }


    return 0; 
}