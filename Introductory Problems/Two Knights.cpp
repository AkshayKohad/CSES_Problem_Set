#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ll n;
    cin>>n;
    
    for(ll i=1;i<=n;i++)
    {

        
        ll val = i*i;
        ll total_ways = (val*(val-1))/2;
        
        ll attack_ways = 4*(i-1)*(i-2);
        
        
        cout<<total_ways-attack_ways<<endl;
        
    }
}
