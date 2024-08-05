#include<bits/stdc++.h>
using namespace std ;

// TC->  4*alpha -> constant time complexity
// SC -> O(n+n)

/*steps 
find ultimate parent (pu, pv)  of U and V
find rank of pu and pv
connects smaller rank to larger rank


question  : why we are joining smaller rank to larger rank -> because it reduces the height of the tree
*/ 


class Disjoint{

    vector<int>rank ;
    vector<int>parent ;

    public:
        Disjoint(int n){
        
        rank.resize(n+1,0) ;
        parent.resize(n+1, 0);

        for( int i=0 ; i <= n ; i++){
            parent[i] = i ;
        }
    }

    int findParent(int n){     // for finding the ultimate parent of the node
        if( parent[n] == n){
            return n ;
        }
        return parent[n] = findParent(parent[n]) ;
    }

    void UnionByRank( int u, int v){

        int parU = findParent(u) ;
        int parV = findParent(v) ;

        if(parU == parV){
            return ;
        }

        if(rank[parU] < rank[parV]){
            parent[parU] = parV ;
        }
        else if(rank[parU] > rank[parV]){
            parent[parV] = parU ;
        }
        else if(rank[parU] == rank[parV]){
            parent[parV] = parU ;
            rank[parU]++ ;
        }
    }

    // void printArray(){
    //     int n = rank.size() ;
    //     cout<<"rank  " ;
    //     for( int i=0; i <= n ; i++){
    //         cout<<rank[i]<<" ";
    //     }
    //     cout<<endl ;
    //     cout<<"parent " ;

    //     for( int i=0; i <= n ; i++){
    //         cout<<parent[i]<<" ";
    //     }
    //     cout<<endl ;
    // }

};

int main(){

    int n = 7;
    // cin>>n ;
    Disjoint obj1(n) ;
    
    obj1.UnionByRank(1,2) ;
    obj1.UnionByRank(2,3) ;
    obj1.UnionByRank(4,5) ;
    obj1.UnionByRank(6,7) ;
    obj1.UnionByRank(5,6) ;

    if(obj1.findParent(3) == obj1.findParent(7)){
        cout<<"present in same set"<<endl ;
    }
    else{
        cout<<"not present in same set"<<endl ;
    }
    // obj1.printArray() ;
    obj1.UnionByRank(3,7) ;

    if(obj1.findParent(3) == obj1.findParent(7)){
        cout<<"present in same set"<<endl ;
    }
    else{
        cout<<"not present in same set"<<endl ;
    }
    // obj1.printArray() ;


    return 0 ;
}