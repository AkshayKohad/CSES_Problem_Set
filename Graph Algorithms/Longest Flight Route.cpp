#include <bits/stdc++.h>
using namespace std;
 
#define boost ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
 
void solve(int src,vector<int>adj[],vector<int>&visited,vector<int>&dp,vector<int>&next_node){
	visited[src] = 1;
 
	for(auto neigh : adj[src]){
		if(visited[neigh]==0) solve(neigh,adj,visited,dp,next_node);
		
		if(dp[neigh] != -1 && dp[src] < dp[neigh]+1){
			dp[src] = dp[neigh] + 1;
			next_node[src] = neigh;
		}
	}
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
 
	vector<int>dp(n+1,-1);
	dp[n] = 1;
 
	vector<int>visited(n+1,0);
 
        vector<int>next_node(n+1,0);
 
	solve(1,adj,visited,dp,next_node);
 
	if(dp[1] == -1){
		cout<<"IMPOSSIBLE\n";
	}else{
		cout<<dp[1]<<"\n";
                int node = 1;
		
		while(node){
			cout<<node<<" ";
			node = next_node[node];
		}
		cout<<"\n";
	}
}
