//Program to store graph using NbyN 2-D Arrays
//S.C: O(N Square)
#include <iostream>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    //Declare the adjacency matrix
    Adj[n+1][n+1];
    //taking edges as input
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        Adj[u][v]=1;
        Adj[v][u]=1;
    }
    
    return 0;
}