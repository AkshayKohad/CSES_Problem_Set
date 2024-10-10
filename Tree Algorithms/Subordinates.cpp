#include <bits/stdc++.h>
using namespace std;

int dfs(int root,vector<int>&subordinates,vector<int>adj[]){
    
    int val = 0;
    
    for(auto u:adj[root]){
        val += dfs(u,subordinates,adj);
    }
    
    subordinates[root]=val;
    return val+1;
}


int main(){
    int n;
    cin>>n;
    
    vector<int>adj[n+1];
    
    for(int i=2;i<=n;i++){
        int val;
        cin>>val;
        
        adj[val].push_back(i);
    }
    
    vector<int>subordinates(n+1,0);
    
    dfs(1,subordinates,adj);
    
    for(int i=1;i<=n;i++){
        cout<<subordinates[i]<<" ";
    }
    
    cout<<"\n";
    
    
}
