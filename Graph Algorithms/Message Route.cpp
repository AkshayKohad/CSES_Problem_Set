#include <bits/stdc++.h>
using namespace std;


int main(){
    int n,m;
    cin>>n>>m;
    
    vector<int>adj[n+1];
    vector<int>visited(n+1,INT_MAX);
    
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    visited[1]=1;
    
    queue<int>q;
    
    q.push(1);
    vector<int>par(n+1);
    par[1]=-1;
    
    
    while(q.empty()==false){
        int cur_nd = q.front();
        q.pop();
        
        if(cur_nd==n)continue;
        
        for(auto u:adj[cur_nd]){
            
            if(visited[u]>visited[cur_nd]+1){
                par[u] = cur_nd;
                visited[u] = visited[cur_nd]+1;
                q.push(u);
            }
        }
    }
    
    if(visited[n]==INT_MAX){
        cout<<"IMPOSSIBLE"<<"\n";
    }
    else{
        cout<<visited[n]<<"\n";
        int cur_nd = n;
        
        vector<int>nodes;
        while(cur_nd!=-1){
            nodes.push_back(cur_nd);
            cur_nd = par[cur_nd];
        }
        
        for(int i=nodes.size()-1;i>=0;i--){
            cout<<nodes[i]<<" ";
        }
        cout<<"\n";
    }
    
   
    return 0;
    
}
