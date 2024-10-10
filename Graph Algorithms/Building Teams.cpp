#include <bits/stdc++.h>
using namespace std;


bool dfs(int src,vector<int>&visited,vector<int>adj[]){
    
    for(auto u:adj[src]){
        if(visited[u]==0){
            visited[u] = 3-visited[src];
            bool res = dfs(u,visited,adj);
            if(res==false)
            return false;
        }
        else{
            if(visited[u]==visited[src])return false;
        }
    }
    
    return true;
}
int main(){
    int n;
    cin>>n;
    
    int m;
    cin>>m;
    
    vector<int>adj[n+1];
    
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
   
    vector<int>visited(n+1,0);
    
    bool res = true;
    
    for(int i=1;i<=n;i++){
        if(visited[i]==0){
            visited[i]=1;
            res = dfs(i,visited,adj);
            
            if(res==false)break;
        }
    }
    
    if(res==false){
        cout<<"IMPOSSIBLE\n";
    }
    else{
        for(int i=1;i<=n;i++){
            cout<<visited[i]<<" ";
        }
        cout<<"\n";
    }
}
