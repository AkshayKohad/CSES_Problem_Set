#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ios_base :: sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll n;
    cin>>n;
    
    vector<ll>a(n);
    
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
    }
    
    ll result = 0;
    
    for(int i=1;i<n;i++)
    {
        if(a[i]<a[i-1])
        {
            result += a[i-1]-a[i];
            a[i] = a[i-1];
        }
    }
    
    cout<<result<<endl;
}
