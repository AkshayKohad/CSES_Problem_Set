#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(vector<ll>&a,ll i,ll sum,vector<ll>&sum_res)
{
    if(i==a.size())
    {
        sum_res.push_back(sum);
        return;
    }
    
    solve(a,i+1,sum+a[i],sum_res);
    solve(a,i+1,sum,sum_res);
}


int main()
{
  ll n;
  cin>>n;
  
  ll x;
  cin>>x;
  
  vector<ll>a(n);
  
  for(ll i=0;i<n;i++)
  cin>>a[i];
  
  vector<ll>half1;
  
  for(ll i=0;i<n/2;i++)
  {
      half1.push_back(a[i]);
  }
  
  vector<ll>half2;
  
  for(ll i=n/2;i<n;i++)
  {
      half2.push_back(a[i]);
  }
  
  vector<ll>sum_half1;
  vector<ll>sum_half2;
  
  solve(half1,0,0,sum_half1);
  solve(half2,0,0,sum_half2);
  
  sort(sum_half2.begin(),sum_half2.end());
  
  
  ll res = 0;
  
  for(auto k:sum_half1)
  {
      
       vector<ll>::iterator lower, upper;
       lower = lower_bound(sum_half2.begin(), sum_half2.end(), x-k);
       upper = upper_bound(sum_half2.begin(), sum_half2.end(), x-k);
 
       ll l = lower - sum_half2.begin();
       ll r = upper - sum_half2.begin();
       
       res += (r-l); 
  }
  
  cout<<res<<endl;
  
  
  
}
