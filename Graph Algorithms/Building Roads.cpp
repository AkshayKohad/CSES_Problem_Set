#include <bits/stdc++.h>
using namespace std;

void dfs(int src,vector<int>&visited,vector<int>adj[]){
    visited[src]=1;
    
    for(auto u : adj[src]){
        if(visited[u]==0){
            dfs(u,visited,adj);
        }
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    
    vector<int>adj[n+1];
    vector<int>visited(n+1,0);
    
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    vector<int>components;
    
    for(int i=1;i<=n;i++){
        
        if(visited[i]==0){
            components.push_back(i);
            dfs(i,visited,adj);
        }
    }
    
    cout<<components.size()-1<<"\n";
    
    for(int i=0;i<components.size()-1;i++){
        cout<<components[i]<<" "<<components[i+1]<<"\n";
    }
    
    return 0;
    
}
