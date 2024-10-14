#include <bits/stdc++.h>
using namespace std;

bool dfs(int src,vector<int>adj[],vector<int>&visited,vector<int>&visited_temp,vector<int>&par,int &nd){
    visited[src]=1;
    visited_temp[src]=1;
    
    
    for(auto u:adj[src]){
         par[u] = src;
        if(visited[u]==0){
            bool res = dfs(u,adj,visited,visited_temp,par,nd);
            if(res)return true;
        }else{
            if(visited_temp[u]==1){
                nd = u;
                return true; 
            }    
        }
    }
    
    visited_temp[src]=0;
    return false;
}

int main(){
   int n,m;
   cin>>n>>m;
   
   vector<int>adj[n+1];
   for (int i=0;i<m;i++){
       int a,b;
       cin>>a>>b;
       
       adj[a].push_back(b);
   }
   
   vector<int>par(n+1,-1);
   vector<int>visited(n+1,0);
   vector<int>temp_visited(n+1,0);
   bool res = false;
   int nd=-1;
   for (int i=1;i<=n;i++){
       if(visited[i]==1)continue;
       
       res = dfs(i,adj,visited,temp_visited,par,nd);
       
       if(res==true){
           break;
       }
   }
   
   if(!res){
       cout<<"IMPOSSIBLE\n";
       return 0;
   }
   int cur = nd;
   for(int i=0;i<n;i++){
       cur = par[cur];
   }
   
   vector<int>result;
   int start_cycle = cur;
   result.push_back(start_cycle);
   cur = par[cur];
   while(cur != start_cycle){
       result.push_back(cur);
       cur = par[cur];
   }
   result.push_back(start_cycle);
   cout<<result.size()<<"\n";
   reverse(result.begin(),result.end());
   
   for(int i=0;i<result.size();i++){
       cout<<result[i]<<" ";
   }
   
}
