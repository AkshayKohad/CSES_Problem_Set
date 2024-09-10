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
    
    ll dp[x+1];
    
    dp[0]=1;
    
    for(ll i=1;i<=x;i++)
    {
        ll res = 0;
        
        for(ll j=0;j<n;j++)
        {
            if(coins[j]>i)
            {
                continue;
            }
            
            res = (res + dp[i-coins[j]])%mod;
        }
        
        dp[i] = res;
    }
    
    cout<<dp[x]<<"\n";
    
    
}
