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
    
    vector<ll>a(n-1);
    
    ll sum = 0;
    for(ll i=0;i<n-1;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    
    ll og_sum = (n*(n+1))/2;
    
    ll missing_number = og_sum-sum;
    
    cout<<missing_number<<endl;
       
}
