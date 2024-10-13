#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
 
void dfs(ll src,vector<ll>&visited,vector<ll>adj[]){
    visited[src]=1;
    for(auto u:adj[src]){
        if(visited[u]==0){
            dfs(u,visited,adj);
        }
    }
}
 
int main(){
 ll n,m;
 cin>>n>>m;
 
 vector<vector<ll>>edges;
 vector<ll>adj_source[n+1];
 vector<ll>adj_destination[n+1];
 for(ll i=0;i<m;i++){
     ll x,y,c;
     cin>>x>>y>>c;
     edges.push_back({x,y,-c});
     adj_source[x].push_back(y);
     adj_destination[y].push_back(x);
 }
 
 vector<ll>visited_source(n+1,0);
 vector<ll>visited_destination(n+1,0);
 dfs(1,visited_source,adj_source);
 dfs(n,visited_destination,adj_destination);
 
 vector<ll>dist(n+1,LLONG_MAX);
 
 dist[1]=0;
 
 for(ll i=0;i<n-1;i++){
     for(auto k:edges){
         ll x = k[0];
         ll y = k[1];
         ll d = k[2];
         
         if(dist[x]==LLONG_MAX)continue;
         
         if(dist[y] > dist[x]+d){
             dist[y] = dist[x]+d;
         }
         
     }
 }
 
 bool isloop = false;
 for(auto k:edges){
         ll x = k[0];
         ll y = k[1];
         ll d = k[2];
         
         if(dist[x]==LLONG_MAX)continue;
         
         
         if((dist[y] > dist[x]+d) && (visited_destination[y] && visited_source[x])){
            isloop = true;
            break;
         }
 }
 
 if(isloop){
     cout<<"-1\n";
 }else{
     cout<<dist[n]*(-1)<<"\n";
 }
 
 
}
