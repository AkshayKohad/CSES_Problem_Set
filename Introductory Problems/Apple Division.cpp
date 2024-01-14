#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ll n;
    cin>>n;
    
    vector<ll>p(n);
    
    ll sum = 0;
    
    for(ll i=0;i<n;i++)
    {
        cin>>p[i];
        sum += p[i];
    }
    
    ll val = pow(2,n)-1;
    
    ll res = INT_MAX;
    
    for(ll i=1;i<=val;i++)
    {
        ll ans = 0; 
        for(ll j=20;j>=0;j--)
        {
            ll bit = (i>>j)&1;
            
            if(bit)
            {
                ans+= p[j];
            }
        }
        
        ll ans1 = sum-ans;
        
        res = min(res,abs(ans-ans1));
    }
    
    cout<<res<<endl;
}
