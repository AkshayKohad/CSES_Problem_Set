#include <bits/stdc++.h>
using namespace std;

void FindEndNode(int src,vector<int>adj[],int &end_node,int par,int &end_node_dist,int dist){
	
	if(end_node_dist < dist){
		end_node_dist = dist;
		end_node = src;
	}
	for(auto neigh : adj[src]){
		if(neigh == par)continue;
		
		FindEndNode(neigh,adj,end_node,src,end_node_dist,dist+1);
	}
}

void FindDistance(int src,vector<int>adj[],int par,int dist,vector<int>&dist_node){
	
	dist_node[src] = dist;
	
	for(auto neigh : adj[src]){
		if(neigh == par) continue;
		
		FindDistance(neigh,adj,src,dist+1,dist_node);
	}
}
int main(){
	int n;
	cin>>n;

	vector<int>adj[n+1];
	
	for(int i=0;i<n-1;i++){
		int src,dest;
		cin>>src>>dest;

		adj[src].push_back(dest);
		adj[dest].push_back(src);

	}
	
	int end_node1 = 1;
	int end_node_dist = 0;
	FindEndNode(1,adj,end_node1,-1,end_node_dist,0);

	int end_node2 = end_node1;
	end_node_dist=0;
	FindEndNode(end_node1,adj,end_node2,-1,end_node_dist,0);

	vector<int>dist_node1(n+1,0);
	FindDistance(end_node1,adj,-1,0,dist_node1);

	vector<int>dist_node2(n+1,0);
	FindDistance(end_node2,adj,-1,0,dist_node2);

	for(int i=1;i<=n;i++){
		cout<<max(dist_node1[i],dist_node2[i])<<" ";
	}

	
}
