/*   Kosaraju algorithm is used for finding the strongly connected components in the directed graph
Steps ->   1) sort the node with smallest finishing time using dfs (The nodes in the last SCC will finish first and will be stored in the last of the stack.)
          2)  reverse the edges of the graph 
          3)  do dfs and count the strongly connected components

          TC -> O((V+E)+(V+E)+(V+E)) ~ O(V+E)
*/

#include<bits/stdc++.h>
using namespace std ;	
    
    void dfs1( int node, vector<int>&vis, vector<vector<int>>& adj,stack<int>&s ){
	    
	    vis[node] = 1 ;
	    for( int adjNode : adj[node]){
	        if( !vis[adjNode]){
	            dfs1(adjNode, vis, adj, s) ;
	        }
	    }
	    s.push(node) ;
	}
	
	void dfs2( int node, vector<vector<int>>&adj2, vector<int>&vis ){
	    
	    vis[node] = 1 ;
	    for( int adjNode : adj2[node]){
	        if( !vis[adjNode]){
	            dfs2(adjNode, adj2, vis) ;
	        }
	    }
	}

    int kosaraju(int V, vector<vector<int>>& adj)
    {
       //start from those nodes first whose finishing time is more
       // reverse the edges
       // count the ssc strongly connected components
       
       stack<int>s ;
       vector<int>vis(V,0) ;
       
       for( int i=0 ; i < V ; i++){
          
          if(!vis[i])
           dfs1(i, vis, adj, s) ;
       }
       
      vector<vector<int>>adj2(V) ;
       
      for( int i=0 ; i < V ; i++){
        vis[i] = 1 ;
           
          for( int adjNode : adj[i]){
              adj2[adjNode].push_back(i) ;
          }
      }
       
      int cnt = 0 ;

      while( !s.empty()){
           
          int node = s.top() ;
          s.pop();
           
          if( !vis[node]){
              cnt++ ;
              dfs2(node , adj2, vis) ;
          }
      }
       
       return cnt ;
    }

    int main(){

        int V, E ;
        cin>>V>>E ;

        vector<vector<int>>adj(V) ;

       for( int i=0 ; i  < E ; i++)
       {
            int u, v ;
            cin>>u>>v ;
            adj[u].push_back(v) ;
        }

        cout<<kosaraju(V, adj)<<"\n" ;
        return 0 ;
    }