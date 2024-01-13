#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

ll modular_exponentiation(ll base,ll power)
{
    if(power==0)
    return 1;
    
    if(power==1)
    return base;
    
    if(power%2==0)
    {
        ll res = modular_exponentiation(base,power/2)%mod;
        
        return (res*res)%mod;
    }
    
    ll res = modular_exponentiation(base,(power-1)/2)%mod;
    
    res = (res*res)%mod;
    
    return (res*base)%mod;
}

int main()
{
    ll n;
    cin>>n;
    
    cout<<modular_exponentiation(2,n);
}
