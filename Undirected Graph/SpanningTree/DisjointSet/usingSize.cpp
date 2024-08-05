#include<bits/stdc++.h>
using namespace std ;
// TC->  4*alpha -> constant time complexity
// SC -> O(n+n+n)
class Disjoint{

    vector<int>rank ;
    vector<int>parent ;
    vector<int>size ;

    public:
        Disjoint(int n){
        
        rank.resize(n+1,0) ;
        parent.resize(n+1, 0);
        size.resize(n+1, 0);

        for( int i=0 ; i <= n ; i++){
            parent[i] = i ;
            size[i] = 1 ;
        }
    }

    int findParent(int n){
        if( parent[n] == n){
            return n ;
        }
        return findParent(parent[n]) ;
    }

    void UnionusingSize( int u, int v){

        int parU = findParent(u) ;
        int parV = findParent(v) ;

        if(parU == parV){
            return ;
        }

        if(size[parU] < size[parV]){
            parent[parU] = parV ;
            size[parV] += size[parU] ; 
        }
        else{
            parent[parV] = parU ;
            size[parU] += size[parV] ; 
        }
    }

};

int main(){

    int n = 7;
    // cin>>n ;
    Disjoint obj1(n) ;
    
    obj1.UnionusingSize(1,2) ;
    obj1.UnionusingSize(2,3) ;
    obj1.UnionusingSize(4,5) ;
    obj1.UnionusingSize(6,7) ;
    obj1.UnionusingSize(5,6) ;

    if(obj1.findParent(3) == obj1.findParent(7)){
        cout<<"present in same set"<<endl ;
    }
    else{
        cout<<"not present in same set"<<endl ;
    }
    obj1.UnionusingSize(3,7) ;

    if(obj1.findParent(3) == obj1.findParent(7)){
        cout<<"present in same set"<<endl ;
    }
    else{
        cout<<"not present in same set"<<endl ;
    }

    return 0 ;
}