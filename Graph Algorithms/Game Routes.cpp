#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

ll solve(int src,vector<int>adj[],vector<int>&visited,int &n){
    if(src==n)return 1;
    
    if(visited[src]!=-1)return visited[src];
    
    ll res = 0;
    for(auto u:adj[src]){
            res = (res+solve(u,adj,visited,n))%mod;
    }
    
    return visited[src] = res;
}
int main(){
      int n,m;
      cin>>n>>m;
      
      vector<int>adj[n+1];
      for(int i=0;i<m;i++){
          int a,b;
          cin>>a>>b;
          adj[a].push_back(b);
      }
      vector<int>visited(n+1,-1);
      
      cout<<solve(1,adj,visited,n);
}
