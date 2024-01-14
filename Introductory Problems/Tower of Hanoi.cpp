#include <bits/stdc++.h> 
using namespace std; 

void towerOfHanoi(int n, int from_rod, int to_rod,int aux_rod,vector<pair<int,int>>&res) 
{ 
	if (n == 0) { 
		return; 
	} 
	towerOfHanoi(n - 1, from_rod, aux_rod, to_rod,res); 
	
	res.push_back({from_rod,to_rod});
	
	towerOfHanoi(n - 1, aux_rod, to_rod, from_rod,res); 
} 

// Driver code 
int main() 
{ 
	int n;
	cin>>n;
	
    vector<pair<int,int>>res;
	// A, B and C are names of rods 
	towerOfHanoi(n, 1, 3, 2,res); 
 
     cout<<res.size()<<endl;
     
     for(int i=0;i<res.size();i++)
     {
         cout<<res[i].first<<" "<<res[i].second<<endl;
     }
} 

// This is code is contributed by rathbhupendra
