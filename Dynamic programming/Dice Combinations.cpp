#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define ll long long

ll solve(ll n,vector<ll>&memo)
{
    if(n==0)
    return 1;
    
    
    if(memo[n]!=-1)
    return memo[n];
    
    
    ll res= 0;
    
    for(ll i=1;i<=min(n,6ll);i++)
    {
        res = (res + solve(n-i,memo))%mod;
    }
    
    return memo[n] = res;
}

int main()
{
    ll n;
    cin>>n;
    
    vector<ll>memo(n+1,-1);
    
    
    cout<<solve(n,memo)<<"\n";
}
