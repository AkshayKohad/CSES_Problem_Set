#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod 1000000007
#define boost ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
 
int main()
{
    boost
    
    ll t;
    cin>>t;
    
    while(t--)
    {
        ll n;
        cin>>n;
        
        //ll dp[n+1][2];
        
        ll prev[2];
        ll cur[2];
        
        // dp[n][1]=1;
        // dp[n][0]=1;
        
        prev[1]=1;
        prev[0]=1;
        
        for(ll i=n-1;i>=1;i--)
        {
            for(ll j=0;j<2;j++)
            {
                //horizontal case
                if(j==0)
                {
                    //dp[i][j] = (2*dp[i+1][0] + dp[i+1][1])%mod;
                    
                    cur[j] = (2*prev[0] + prev[1])%mod;
                }
                else{
                    //dp[i][j] = (dp[i+1][0] + 4*dp[i+1][1])%mod;
                    cur[j] = (prev[0] + 4*prev[1])%mod;
                }
            }
            
            prev[0] = cur[0];
            prev[1] = cur[1];
        }
        
        cout<<(prev[1] + prev[0])%mod<<"\n";
        
        
    }
    
    
    
    return 0;
}
