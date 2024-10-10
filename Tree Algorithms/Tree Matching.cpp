#include <bits/stdc++.h>
using namespace std;


int solve(int nd,vector<int>adj[],int status,int par,vector<vector<int>>&memo){
    
    if(memo[nd][status]!=-1)return memo[nd][status];
    
    
    if(status){
        int ans=0;
        
        for(auto u:adj[nd]){
            if(par==u)continue;
            
            ans += solve(u,adj,1,nd,memo);
        }
        
        int myres=0;
        
        for(auto u:adj[nd]){
            if(par==u)continue;
            
            myres = max(myres,ans-memo[u][1]+1+solve(u,adj,0,nd,memo));
        }
        
        return memo[nd][status] = myres;
    }else{
        int ans=0;
        
        for(auto u:adj[nd]){
            if(par==u)continue;
            
            ans += solve(u,adj,1,nd,memo);
        }
        
        return memo[nd][status]=ans;
    }
}

int main(){
    int n;
    cin>>n;
    
    vector<int>adj[n+1];
    
    for(int i=0;i<n-1;i++){
        int x,y;
        cin>>x>>y;
        
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    vector<vector<int>>memo(n+1,vector<int>(2,-1));
    cout<<max(solve(1,adj,0,-1,memo),solve(1,adj,1,-1,memo));
}
