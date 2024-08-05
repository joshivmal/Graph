/*
floyd Warshall -> speciality ->   it is multisource shortest path algorithm means it finds shortest path for 
every single node of the graph while bellman ford and dijasktra's handles are single source shortest path algorithm

->  it handles negative edges and negative cycles
if there are no negative cycles we can use  dijasktra's for multisource shortest path algorithm and TC is (V*(E+V)logV)

TC -> O(V^3)
SC ->O(V^2)


*/



#include<bits/stdc++.h>
using namespace std ;
int main(){

    int V=4 ;
    // cin>>V;
    vector<vector<int>>matrix(V,vector<int>(V,-1)) ;   // representation in 2D vector

    matrix[0][1] = 2;          //edges
	matrix[1][0] = 1;
	matrix[1][2] = 3;
	matrix[3][0] = 3;
	matrix[3][1] = 5;
	matrix[3][2] = 4;

    for( int i=0 ; i < V ; i++){
        for( int j =0 ; j < V ; j++){
            if(i==j){
                matrix[i][j] = 0 ;  }     // putting arr[0][0] = 0
            else if( matrix[i][j] == -1){
                matrix[i][j] = 1e9 ;
            }
        }
    }

    for( int k=0 ; k < V ; k++){
        for( int i=0 ; i < V ; i++){
            for( int j=0 ; j < V ; j++){

                matrix[i][j] = min( matrix[i][j], matrix[i][k]+matrix[k][j]) ;
            }
        }
    }

    for( int i=0 ; i < V ; i++){
        if(matrix[i][i] < 0){
            cout<<"It has negative cycle"<<endl ;
            break ;
        }
    }

        for( int i=0 ; i < V ; i++){
            for( int j=0 ; j < V ; j++){
                if( matrix[i][j] == 1e9){
                    matrix[i][j] = -1     ;      // unreachable nodes
                }
            }}

        for( int i=0 ; i < V ; i++){
            for( int j=0 ; j < V ; j++){
                cout<<matrix[i][j]<<" " ;
            }
            cout<<endl ;
        }



    return 0 ;
}