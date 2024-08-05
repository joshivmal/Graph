#include<bits/stdc++.h>
using namespace std ;

// TC =>   O(ElogE + 4*2*E) -> sorting +( disjoint[ findParent + Union ] )
// SC => O(V+V+(V+E)) -> parents, size, adjacent list
class Disjoint{

    vector<int>rank ;
    vector<int>parents ;
    vector<int>size ;

    public:
    
    Disjoint(int n)
    {
        rank.resize(n+1,0) ;
        size.resize(n+1,1) ;
        parents.resize(n+1,0);

        for( int i=0; i <= n ; i++ ){
            parents[i] = i ;
        }
    }
    
    int findParent( int n){

        if(parents[n] == n){
            return n ;
        }
        return parents[n] = findParent(parents[n]) ;
    }

    void UnionbySize(int u, int v){
        int parU = findParent(u) ;
        int parV = findParent(v) ;

        if(parU == parV){
            return ;
        }

        if( size[parU] < size[parV] ){
            parents[parU] = parents[parV] ;
            size[parV] += size[parU] ;
        }
        else{
            parents[parV] = parents[parU] ;
            size[parU] += size[parV] ;
        }
    }

    void UnionbyRank(int u, int v){
        int parU = findParent(u) ;
        int parV = findParent(v) ;

        if(parU == parV){
            return ;
        }

        if( rank[parU] < rank[parV] ){
            parents[parU] = parents[parV] ;

        }
        else if( rank[parV] < rank[parU] ){
            parents[parV] = parents[parU] ;
        }
        else{
            parents[parV] = parents[parU] ;
            rank[parU]++ ;
        }
    }

};


int main(){

    int V,E ;
    cin>>V>>E ;

    vector<vector<int>>adj[V] ;

    for( int i=0 ; i < E ; i++){           // the array we get during implementation
        int u,v,w ;
        cin>>u>>v>>w ;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    vector< pair <int,pair<int,int> > >Edges ;

    for( int i=0 ; i < V ; i++){       //the array we have to form

        for( auto it : adj[i]){

            int node = i ;
            int v = it[0] ;
            int w = it[1] ;

            Edges.push_back({w,{i,v}}) ;
        }
    
    }

    sort(Edges.begin(), Edges.end()) ;

    Disjoint obj1(V+1) ;
    long long MSTsum = 0 ;
    vector< pair<int,int> >MST ;

    for( int i=0 ; i < Edges.size() ; i++){
        int w = Edges[i].first ;
        int u = Edges[i].second.first ;
        int v = Edges[i].second.second ;

        if(obj1.findParent(u) == obj1.findParent(v)){
            continue ;
        }
        else{
            MSTsum += w ;
            obj1.UnionbySize(u,v) ;
            MST.push_back({u,v}) ;
        }
    }
    cout<<"MSTsum "<<MSTsum<<endl ;

    cout<<" Spanning tree "<<endl ;
    for( int i=0 ; i < MST.size() ; i++){

        cout<<"( "<<MST[i].first<<" "<<MST[i].second<<" ) "<<endl ;
    }


    return 0 ;
}