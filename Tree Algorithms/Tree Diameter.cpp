#include <bits/stdc++.h>
using namespace std;

void FindEndNode(int src,vector<int>adj[],int &end_node,int &end_node_dist,int dist,int par){
    if(end_node_dist<dist){
        end_node = src;
	    end_node_dist = dist;
    }
	
	
	for(auto neigh : adj[src]){
	    if(neigh==par)continue;
	    
		FindEndNode(neigh,adj,end_node,end_node_dist,dist+1,src);
	}

	return;
}

int FindDiameter(int src,vector<int>adj[],int par){
	int res = 0;

	for(auto neigh : adj[src]){
	    if(neigh==par)continue;
		res = max(res,1 + FindDiameter(neigh,adj,src));
	}
	return res;
}
int main(){
	int n;
	cin>>n;

	vector<int>adj[n+1];

	for(int i=0;i<n-1;i++){
		int par,child;
		cin>>par>>child;
		
		adj[par].push_back(child);
	    adj[child].push_back(par);
	}

	int end_node = 1;
    
    int end_node_dist = 0;
    
	FindEndNode(1,adj,end_node,end_node_dist,0,-1);
 
    
	int Diameter = FindDiameter(end_node,adj,-1);
    
	cout<<Diameter<<"\n";
}
