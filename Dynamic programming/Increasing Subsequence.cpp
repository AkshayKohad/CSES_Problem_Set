#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll search(vector<ll>&res,ll val)
{
    ll l=0;
    ll r = res.size()-1;
    ll ans = -1;
    while(l<=r)
    {
        ll mid = (l+r)/2;
        
        if(res[mid]==val)
        return mid;
        
        else if(res[mid]>val)
        {
            ans = mid;
            r = mid-1;
        }
        else{
            l = mid+1;
        }
        
    }
    
    if(ans==-1)
    ans=0;
    
    return ans;
}
int main()
{
    ll n;
    cin>>n;
    
    vector<ll>a(n);
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
    }
    
    
    vector<ll>res;
    
    for(ll i=0;i<n;i++)
    {
        if(res.size()==0 || res.back()<a[i])
        {
            res.push_back(a[i]);
        }
        
        else{
            ll index = search(res,a[i]);
            
            res[index] = a[i];
        }
    }
    
    cout<<res.size()<<"\n";
    
}
