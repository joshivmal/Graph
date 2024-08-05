//bridgess in directed graph means all those edges, if we remove them then it will break that graph into different components
// observation :  all edges which are not part a of cycle  are bridgess 
//Approach ->  we iterate one by one in k sized path  and mark TOI & LTOI a number from 1 to k according to path, if a node
//              finds a adjacent node except parent  whose rank  is smaller than current node, present in path, then it means
//                it is visited previously and congratulation you found a  cycle in a graph, now the current node knows there
//                 is a cycle, then how upper nodes will know there is cycle for which we use minimum time of insertion array 
//                during backtracking  if timeofInsertion[node] >= minimumTimeofInsertion[adjNode] , then it is part of cycle
//              if  timeofInsertion[node] < minimumTimeofInsertion[adjNode], then that node is not visited earlier 
//              and edge  is not a part of a cycle (  which is bridges)


// we do DFS in this and use three arrays, first is 
                //visited array,( for marking the array) 
                // time of insertion (when node is first time visited)  TOI
                // minimum time of insertion ( adjacent node with smallest time of insertion)   LTOI


#include<bits/stdc++.h>
using namespace std ;

int timer = 1 ;

void dfs(int node, int parent, vector<int>&TOI, vector<int>&MTOI, vector<int>&vis, vector<int>adj[], vector<pair<int,int>>&bridges){

    vis[node] = 1 ;
    TOI[node] = MTOI[node] =  timer ;
    timer++ ;

    for( int adjNode : adj[node]){

        if( adjNode == parent) continue ;
        if(!vis[adjNode]){
            dfs(adjNode, node, TOI, MTOI, vis, adj, bridges) ;
            MTOI[node] = min(MTOI[node], MTOI[adjNode]) ;
            if( TOI[node] < MTOI[adjNode]){
                bridges.push_back({adjNode,node}) ;
            }
        }
        else{
            MTOI[node] = min(MTOI[node],MTOI[adjNode]) ;
        }
    }

}

int main(){

    int V, E ;
    cin>>V>>E ;             // vertices and edges
    vector<int>adj[V+1] ;   // adjaceny list

    for( int i=0 ; i < E ; i++){    // undirected graph
        int u, v ;
        cin>>u>>v ;
        adj[u].push_back(v) ;
        adj[v].push_back(u) ;
    }

    vector<int>vis(V+1,0) ;
    vector<int>TOI(V+1) ;
    vector<int>MTOI(V+1) ;
    vector<pair<int,int>>bridges ;

    dfs(1, -1, TOI, MTOI, vis, adj, bridges) ;

    cout<<"BRIDGES"<<endl ;
    for( int i=0 ; i < bridges.size() ; i++){
        cout<<bridges[i].first<<" "<<bridges[i].second<<endl ;
    }
    return 0 ;
}