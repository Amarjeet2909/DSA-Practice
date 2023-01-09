//Program to store graph using Adjecency list and using combination of Arrays & Vector
//S.C: O(N+2E)
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
 
    vector <int> adj[n+1];
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u); //In case of directed graph we will omit this step
    }
    return 0;
}