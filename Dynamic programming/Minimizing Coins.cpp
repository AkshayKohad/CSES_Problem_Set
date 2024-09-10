#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define boost  ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

ll solve(ll i,ll x,vector<ll>&coins,ll &n)
{
    if(x==0)
    return 0;
    
    if(x<0)
    return INT_MAX;
    
    if(i==n)
    return INT_MAX;
    
    
    ll res = INT_MAX;
    
    res = min(1+solve(i,x-coins[i],coins,n),solve(i+1,x,coins,n));
    
    return res;
    
}

int main()
{
  ll n,x;
  cin>>n>>x;
  
  vector<ll>coins(n);
  
  for(ll i=0;i<n;i++)
  cin>>coins[i];
  
  //cout<<solve(0,x,coins,n)<<"\n";
  
  
  
  vector<ll> prev(x+1);
  
  for(ll i=0;i<=x;i++)
  {
      prev[i]=INT_MAX;
  }
  
  
  
  vector<ll>cur(x+1);
  
  for(ll i=n-1;i>=0;i--)
  {
      for(ll j=0;j<=x;j++)
      {
          if(j==0)
          {
           cur[j]=0;
           continue;
          }
          
          
          ll state = INT_MAX;
          ll state2 = INT_MAX;
          
          if(j-coins[i]>=0)
          {
              state = 1+cur[j-coins[i]];
          }
          
          state2 = prev[j];
          
          cur[j] = min(state,state2);
          
      }
      
      prev = cur;
      
  }
  
  if(cur[x]==INT_MAX)
  cout<<"-1\n";
  
  else
  cout<<cur[x]<<"\n";
  
}
