#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define boost  ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define mod 1000000007

int main()
{
    
    boost
    
    ll n,x;
    cin>>n>>x;
    
    vector<ll>coins(n);
    
    for(ll i=0;i<n;i++)
    cin>>coins[i];
    
    vector<ll> prev(x+1);
    vector<ll> cur(x+1);
    
    for(ll i=1;i<=x;i++)
    prev[i] = 0;
    
    prev[0] = 1;
    
    
    
    for(ll i=n-1;i>=0;i--)
    {
        
            
        for(ll j=0;j<=x;j++)
        {
           if(j==0)
           {
               cur[j]=1;
               continue;
           }
           
           ll state = 0;
           ll state1 = 0;
           
           if(j-coins[i]>=0)
           { 
            state = cur[j-coins[i]];
           }
           
           state1 = prev[j];
           
           cur[j] = (state + state1)%mod;
        }
        
        prev = cur;
        
    }
    
    cout<<cur[x]<<"\n";
    
    
}
