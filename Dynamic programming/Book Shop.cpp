#include <bits/stdc++.h>
using namespace std;

#define boost ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

#define ll long long

ll solve(ll i,ll &n,vector<ll>&h,vector<ll>&s,ll x)
{
    if(x<0)
    {
        return INT_MIN;
    }
    
    if(i==n || x==0)
    return 0;
    
    ll res = max(s[i]+solve(i+1,n,h,s,x-h[i]),solve(i+1,n,h,s,x));
    
    return res;
}

int main()
{
    ll n,x;
    
    cin>>n>>x;
    vector<ll>h(n),s(n);
    
    
    for(ll i=0;i<n;i++)
    {
        cin>>h[i];
    }
    
    for(ll i=0;i<n;i++)
    {
        cin>>s[i];
    }
    
    //cout<<solve(0,n,h,s,x);
    
    //ll dp[n+1][x+1];
    
    vector<ll>prev(x+1);
    vector<ll>cur(x+1);
    for(ll i=0;i<=x;i++)
    {
        //dp[n][i]=0;
        prev[i]=0;
    }
    
    // for(ll i=0;i<=n;i++)
    // {
    //     dp[i][0]=0;
    // }
    
    for(ll i=n-1;i>=0;i--)
    {
        for(ll j=0;j<=x;j++)
        {
            if(j==0)
            {
                cur[j]=0;
            }
            ll state=INT_MIN;
            ll state2=INT_MIN;
            
            if(j-h[i]>=0)
            {
                // state = s[i]+dp[i+1][j-h[i]];
                state = s[i]+prev[j-h[i]];
            }
            
            //state2 = dp[i+1][j];
            state2 = prev[j];
            
           // dp[i][j] = max(state,state2);
           cur[j] = max(state,state2);
           
        }
        
        prev = cur;
    }
    
    
    //cout<<dp[0][x]<<"\n";
    cout<<cur[x]<<"\n";
}
