#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

vector<pair<ll,ll>>directions = {{1,0},{0,1}};

ll solve(ll i,ll j,ll n,ll m,vector<vector<char>>&grid,vector<vector<ll>>&memo)
{
    if(i==n-1 && j==m-1)
    {
        return 1;
    }    
    
    if(memo[i][j]!=-1)
     return memo[i][j];
    
    ll res = 0;
    
    for(auto k:directions)
    {
      ll x=i+k.first;
      ll y=j+k.second;
      
      if(x>=n || y>=m || grid[x][y]=='*') continue;
      
      res += solve(x,y,n,m,grid,memo);
    }  
    
    return memo[i][j] = res;
}
int main()
{
  ll n;
  cin>>n;
  
  vector<vector<char>>grid(n,vector<char>(n));
  
  for(ll i=0;i<n;i++)
  {
      for(ll j=0;j<n;j++)
       cin>>grid[i][j];
  }
  
  vector<vector<ll>>memo(n,vector<ll>(n,-1));
  
  cout<<solve(0,0,n,n,grid,memo)<<"\n";
   
}
