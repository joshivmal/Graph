/*
Articulation points are those vertices, if we remove them from the graph them it will increase the number of 
connected components of the graph, we do hashing in articulation points for vertices because we can visit one articulation
vertice multiple times
*/
#include<bits/stdc++.h>
using namespace std ;

int timer = 1 ;
void dfs(int node, int parent, vector<int>&vis,vector<int>&TOI,vector<int>&minTOI,vector<int>adj[],vector<int>&articulationPoints){
    vis[node] = 1 ;
    TOI[node] = minTOI[node] = timer;
    timer++ ;
    int child = 0 ;
    for( int adjNode : adj[node]){
        if( adjNode == parent){ continue ;}
        if( !vis[adjNode]){
            dfs(adjNode, node, vis, TOI, minTOI, adj, articulationPoints);
            minTOI[node] =  min(minTOI[adjNode],minTOI[node]) ;
            if( TOI[node] <= minTOI[adjNode] && parent  != -1 ){
                articulationPoints[node] = 1;
            }
            child++ ;
        }
        else{
            minTOI[node] = min(TOI[adjNode],minTOI[node]) ;   //edge case
        }

    }
     if(child > 1 && parent == -1){
            articulationPoints[node] = 1 ;       //edge case
        }


}

int main(){
    int V,E ;
    cin>>V>>E ;
    vector<int>adj[V] ;
    // vector<vectot<int>>adj(V)   //method 2

    for( int i=0; i<E ; i++){
        int u, v ;
        cin>>u>>v ;
        adj[u].push_back(v) ;
        adj[v].push_back(u) ;
    }

    vector<int>vis(V,0) ;
    vector<int>TOI(V) ;
    vector<int>minTOI(V) ;
    vector<int>articulationPoints(V,0) ;

    for( int i=0 ; i < V ; i++){
        if(!vis[i]){
        dfs(i,-1,vis,TOI,minTOI, adj, articulationPoints);
        }
    }

    vector<int>ans ;

    for( int i=0 ; i < V ; i++){
        if(articulationPoints[i] == 1){
            ans.push_back(i) ;
            cout<<ans[i]<< " " ;
        }
    }


    return 0 ;
}