#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>>directions = {{1,0},{0,1},{-1,0},{0,-1}};


void dfs(int x,int y,int &n,int &m,vector<vector<int>>&visited,vector<vector<char>>&building){
    
    visited[x][y]=1;
    
    for(auto k:directions){
        int xf = x+k.first;
        int yf = y+k.second;
        
        if(xf>=n || yf>=m || xf<0 || yf<0 || building[xf][yf]=='#' || visited[xf][yf]==1) continue;
        
        dfs(xf,yf,n,m,visited,building);
    }
}


int main(){
    int n,m;
    cin>>n>>m;
    
    vector<vector<char>>building(n,vector<char>(m));
    vector<pair<int,int>>floor;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>building[i][j];
            
            if(building[i][j]=='.'){
                floor.push_back({i,j});
            }
        }
    }
    
    vector<vector<int>>visited(n,vector<int>(m,0));
    int cnt_rooms = 0;
    
    for(int i=0;i<floor.size();i++){
        int x = floor[i].first;
        int y = floor[i].second;
        
        if(visited[x][y]==0){
            cnt_rooms++;
            dfs(x,y,n,m,visited,building);
        }
    }
    
    cout<<cnt_rooms<<"\n";
}
