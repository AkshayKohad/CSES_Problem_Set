#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
 
#define ll int
#define boost ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
 
int main()
{
    boost
    ll a,b;
    cin>>a>>b;
    
    ll dp[a+1][b+1];
    
    for(ll i=0;i<=b;i++)
    dp[0][i]=0;
    
    for(ll i=0;i<=a;i++)
    dp[i][0]=0;
    
    for(ll i=0;i<=min(a,b);i++)
    dp[i][i]=0;
    
    for(ll i=1;i<=a;i++)
    {
        dp[i][1]=i-1;
    }
    for(ll i=1;i<=b;i++)
    {
        dp[1][i]=i-1;
    }
    
    for(ll i=2;i<=a;i++)
    {
        for(ll j=2;j<=b;j++)
        {
            if(i==j)continue;
            
            ll res = INT_MAX;
    
    
            for(ll z=1;z<i;z++)
            {
              res = min(res,1+dp[z][j]+dp[i-z][j]);
            }
    
            for(ll z=1;z<j;z++)
            {
                res = min(res,1+dp[i][z]+dp[i][j-z]);
            }
            
            dp[i][j] = res;
        }
        
    }
    
    cout<<dp[a][b]<<"\n";
}
